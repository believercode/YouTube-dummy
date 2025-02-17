from flask import Flask, render_template, request, jsonify
import requests
import os
import sys
from datetime import datetime
from dotenv import load_dotenv

load_dotenv()

app = Flask(__name__)
OPENWEATHER_API_KEY = os.getenv('OPENWEATHER_API_KEY')

def kelvin_to_celsius(kelvin):
    return kelvin - 273.15

def get_weather_data(lat, lon):
    try:
        # Current weather
        current_weather_url = f"https://api.openweathermap.org/data/2.5/weather?lat={lat}&lon={lon}&appid={OPENWEATHER_API_KEY}"
        current_response = requests.get(current_weather_url)
        
        if current_response.status_code != 200:
            return {"error": f"Failed to fetch weather data: {current_response.json().get('message', 'Unknown error')}"}
        
        current_data = current_response.json()
        
        # 5-day forecast
        forecast_url = f"https://api.openweathermap.org/data/2.5/forecast?lat={lat}&lon={lon}&appid={OPENWEATHER_API_KEY}"
        forecast_response = requests.get(forecast_url)
        
        if forecast_response.status_code != 200:
            return {"error": f"Failed to fetch forecast data: {forecast_response.json().get('message', 'Unknown error')}"}
        
        forecast_data = forecast_response.json()
        
        # Process forecast data (one entry per day)
        forecast = []
        seen_dates = set()
        
        for item in forecast_data['list']:
            date = datetime.fromtimestamp(item['dt']).strftime('%Y-%m-%d')
            if date not in seen_dates:
                seen_dates.add(date)
                forecast.append({
                    'date': date,
                    'temp': round(kelvin_to_celsius(item['main']['temp'])),
                    'description': item['weather'][0]['description'],
                    'icon': item['weather'][0]['icon']
                })
                if len(forecast) >= 5:  # Limit to 5 days
                    break
        
        return {
            'city': current_data['name'],
            'temp': round(kelvin_to_celsius(current_data['main']['temp'])),
            'feels_like': round(kelvin_to_celsius(current_data['main']['feels_like'])),
            'humidity': current_data['main']['humidity'],
            'wind_speed': round(current_data['wind']['speed'], 1),
            'description': current_data['weather'][0]['description'],
            'icon': current_data['weather'][0]['icon'],
            'forecast': forecast
        }
    except Exception as e:
        print(f"Error in get_weather_data: {str(e)}")
        return {"error": "Failed to process weather data"}

def find_best_city_match(city_name):
    # First try without country code
    url = f"http://api.openweathermap.org/geo/1.0/direct?q={city_name}&limit=5&appid={OPENWEATHER_API_KEY}"
    response = requests.get(url)
    
    if response.status_code != 200:
        return None
        
    locations = response.json()
    
    if not locations:
        return None
        
    # Look for exact matches first
    for loc in locations:
        if loc.get('name').lower() == city_name.lower():
            # For exact name matches, prefer places with state/province info
            if loc.get('state'):
                return loc
    
    # If no preferred match found, return the first result
    return locations[0]

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/weather')
def weather():
    try:
        if 'lat' in request.args and 'lon' in request.args:
            lat = float(request.args.get('lat'))
            lon = float(request.args.get('lon'))
        elif 'city' in request.args:
            city = request.args.get('city').strip()
            # Get coordinates for city with more results and include country in search
            geocoding_url = f"http://api.openweathermap.org/geo/1.0/direct?q={city}&limit=10&appid={OPENWEATHER_API_KEY}"
            geo_response = requests.get(geocoding_url)
            
            if geo_response.status_code != 200:
                return jsonify({"error": f"Failed to find city: {geo_response.json().get('message', 'Unknown error')}"})
            
            locations = geo_response.json()
            if not locations:
                return jsonify({"error": "City not found"})
            
            # Get the first result but include country info in the response
            location = locations[0]
            lat = location['lat']
            lon = location['lon']
            
            # Print location details for debugging
            print(f"Found city: {location['name']}, {location.get('state', '')}, {location.get('country', '')}")
            print(f"All matches: {[(loc['name'], loc.get('country', '')) for loc in locations]}")
        else:
            return jsonify({"error": "Invalid request parameters"})
        
        weather_data = get_weather_data(lat, lon)
        if 'city' in weather_data:
            # Add country info to the city name
            weather_data['city'] = f"{weather_data['city']}, {location.get('country', '')}"
        return jsonify(weather_data)
    except Exception as e:
        print(f"Error in weather route: {str(e)}")
        return jsonify({"error": "Failed to process request"})

if __name__ == '__main__':
    cli = sys.modules['flask.cli']
    cli.show_server_banner = lambda *x: None
    app.config['TEMPLATES_AUTO_RELOAD'] = True
    app.run(host='0.0.0.0', port=8080, debug=True, threaded=True)
