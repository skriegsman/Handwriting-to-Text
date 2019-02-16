""" File holds removed statements I might want to add back in later """

workingImage = cv2.adaptiveThreshold(workingImage, 255, cv2.ADAPTIVE_THRESH_GAUSSIAN_C, cv2.THRESH_BINARY, 5, 1)


#Save image to storage so it can be analysed
filename = "{}.png".format(os.getpid())
cv2.imwrite(filename, 0)

text = pytesseract.image_to_string(Image.open(filename), lang="eng")
os.remove(filename)
