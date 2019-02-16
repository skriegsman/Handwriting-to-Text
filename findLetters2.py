import pytesseract
from PIL import Image, ImageEnhance, ImageFilter
from textblob import TextBlob
im = Image.open("pictures\hp.png") # the second one 
im = im.filter(ImageFilter.MedianFilter())
enhancer = ImageEnhance.Contrast(im)
enhancer1 = ImageEnhance.Sharpness(im)
enhancer2 = ImageEnhance.Color(im)
im = enhancer1.enhance(2)
im = enhancer2.enhance(0)
im = im.convert('1')
im.save('temp2.jpg')
text = pytesseract.image_to_string(Image.open('temp2.jpg'))
text2 = TextBlob(text).correct()
print(text2)
