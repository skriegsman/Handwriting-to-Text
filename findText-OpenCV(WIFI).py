import cv2
import pytesseract
import numpy as np

""" ---Initial Image Processing--- """
image = cv2.imread("pictures/HPlarge.png", 0)
ret, thresh = cv2.threshold(image,0,255,cv2.THRESH_BINARY+cv2.THRESH_OTSU)
blur = cv2.GaussianBlur(thresh, (1,1), 0)
invert = cv2.bitwise_not(blur)

""" ---Auto Rotates the Image to Correct Skew--- """
coords = np.column_stack(np.where(invert > 0))
angle = cv2.minAreaRect(coords)[-1]

if angle < -45: angle = -(90 + angle)
else: angle = -angle

(h, w) = image.shape[:2]
center = (w // 2, h // 2)
M = cv2.getRotationMatrix2D(center, angle, 1.0)
rotated = cv2.warpAffine(invert, M, (w, h), flags=cv2.INTER_CUBIC, borderMode=cv2.BORDER_REPLICATE)
reInvert = cv2.bitwise_not(rotated)


""" ---Auto Crop Image using the above minAreaRect--- """
points = np.argwhere(reInvert==0)
points = np.fliplr(points)
x, y, w, h = cv2.boundingRect(points)
crop = reInvert[y:y+h, x:x+w]

""" ---Finds the text in the processed image--- """
text = pytesseract.image_to_string(crop, config='--psm 1 --oem 1')
print(text)
