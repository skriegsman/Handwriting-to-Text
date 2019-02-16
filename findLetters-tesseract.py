import pytesseract
from PIL import Image, ImageEnhance, ImageFilter
from textblob import TextBlob

originalImage = Image.open("pictures\hp.png")
workingImage = originalImage.copy()
workingImage = originalImage.filter(ImageFilter.MedianFilter())

enhanceSharpness = ImageEnhance.Sharpness(workingImage)
enhanceColor = ImageEnhance.Color(workingImage)

workingImage = enhanceSharpness.enhance(2)
workingImage = enhanceColor.enhance(0)
workingImage = workingImage.convert('1')

text = pytesseract.image_to_string(workingImage)
#correctedText = TextBlob(text).correct()

print(text)
