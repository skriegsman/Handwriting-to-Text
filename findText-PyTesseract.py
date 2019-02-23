import cv2
import pytesseract
import numpy as np


""" ---Reads in image (Will come from app in future)--- """
#Reads in image as grey scale (0) from the pictures folder
image = cv2.imread("pictures/skew1.png", 0)


""" ---Auto Blurs/Thresholds the Image Based on Initial Sharpness--- """
blur = cv2.GaussianBlur(image, (1,1), 0)
#Convert greyscale to only white or only black
#Link explaining Otsu's Thresholding:
#    --> https://docs.opencv.org/3.0-beta/doc/py_tutorials/py_imgproc/py_thresholding/py_thresholding.html
ret, thresh = cv2.threshold(blur,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
cv2.imshow("Blured & Thresholded Image", blur) #TESTING ONLY


""" ---Auto Rotates the Image to Correct Skew--- """
#Inverts image to white text on black background ---(Add check for preinverted image)---
invert = cv2.bitwise_not(thresh)
coords = np.column_stack(np.where(invert > 0))
angle = cv2.minAreaRect(coords)[-1]

if angle < -45: angle = -(90 + angle)
else: angle = -angle

(h, w) = image.shape[:2]
center = (w // 2, h // 2)
M = cv2.getRotationMatrix2D(center, angle, 1.0)
rotated = cv2.warpAffine(invert, M, (w, h), flags=cv2.INTER_CUBIC, borderMode=cv2.BORDER_REPLICATE)
reInvert = cv2.bitwise_not(rotated)
cv2.imshow("Rotated Image", reInvert) #TESTING ONLY


""" ---Auto Crop Image using the above minAreaRect--- """
points = np.argwhere(reInvert==0)
points = np.fliplr(points)
x, y, w, h = cv2.boundingRect(points)
crop = reInvert[y:y+h, x:x+w]
cv2.imshow("Cropped Image", crop) #TESTING ONLY

""" ---Finds the text in the processed image--- """
text = pytesseract.image_to_string(crop, config='--psm 1 --oem 1')
print(text)

cv2.waitKey(0) #TESTING ONLY
cv2.destroyAllWindows() #TESTING ONLY
