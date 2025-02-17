# Weather App

A mobile-friendly weather application built with Flask that shows current weather conditions for any city.

## Features
- Current temperature in Celsius
- Weather description with icons
- Humidity and wind speed information
- Mobile-responsive design
- Clean and modern UI

## Setup Instructions

1. First, install the required packages:
```bash
pip install -r requirements.txt
```

2. Get an API key from OpenWeatherMap:
   - Go to https://openweathermap.org/
   - Sign up for a free account
   - Get your API key from your account dashboard

3. Create a `.env` file in the project root:
   - Copy `.env.example` to `.env`
   - Replace `your_api_key_here` with your actual OpenWeatherMap API key

4. Run the application:
```bash
python app.py
```

5. Open your browser and go to `http://127.0.0.1:5000`

## Usage
- Enter a city name in the search box
- Click "Get Weather" or press Enter
- View the current weather conditions for your chosen city

## Mobile Access
To access the app from your phone while developing:
1. Make sure your phone and computer are on the same WiFi network
2. Find your computer's local IP address
3. Run Flask with host='0.0.0.0':
   ```python
   app.run(debug=True, host='0.0.0.0')
   ```
4. On your phone, visit `http://[your_computer_ip]:5000`
