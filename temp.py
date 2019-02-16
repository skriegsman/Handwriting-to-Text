""" File holds removed statements I might want to add back in later """

workingImage = cv2.adaptiveThreshold(workingImage, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 5, 1)


#Save image to storage so it can be analysed
filename = "{}.png".format(os.getpid())
cv2.imwrite(filename, 0)

text = pytesseract.image_to_string(Image.open(filename), lang="eng")
os.remove(filename)

#add adaptive thresholding  with a gaussian blur here to get rid of grays and make the page black and white only
#guassian blur smooths immage and gets rid of misc noise in the image
#workingImage = cv2.GaussianBlur(workingImage, (5, 5), 0)
#workingImage = cv2.threshold(workingImage, 0, 255, cv2.THRESH_BINARY + cv2.THRESH_OTSU)[1]
