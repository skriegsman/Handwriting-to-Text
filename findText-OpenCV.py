import cv2
import pytesseract
import matplotlib.pyplot as plt
import numpy as np

image = cv2.imread("pictures/skew1.png", 0)
ret, thresh = cv2.threshold(image,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
invert = cv2.bitwise_not(thresh)

#auto crop here

#auto blur

""" ---Auto Rotates the Image to Correct Skew--- """
coords = np.column_stack(np.where(invert > 0))
angle = cv2.minAreaRect(coords)[-1]

if angle < -45: angle = -(90 + angle)
else: angle = -angle

(h, w) = image.shape[:2]
center = (w // 2, h // 2)
M = cv2.getRotationMatrix2D(center, angle, 1.0)
rotated = cv2.warpAffine(invert, M, (w, h), flags=cv2.INTER_CUBIC, borderMode=cv2.BORDER_REPLICATE)

#text = pytesseract.image_to_string(rotated, config= '--psm 1 --oem 1')
#print(text)

cv2.imshow("image", image)
cv2.imshow("rotate", rotated)
cv2.waitKey(0)
cv2.destroyAllWindows()
