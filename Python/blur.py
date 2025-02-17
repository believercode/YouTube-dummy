from PIL import Image, ImageFilter

# Open the image file
image = Image.open("hat.png")

# Apply the blur filter
blurred_image = image.filter(ImageFilter.BLUR)

# Save the blurred image
blurred_image.save("blurred_image.jpg")
