"""
------------------------------------------------------------------------------------------------------------------
-----    Holds old statements and sections of code that can be reimplemented later or might have some use    -----
------------------------------------------------------------------------------------------------------------------
"""


# TODO: finds original width and height of the image to be used in resizing TESTING ONLY
sizeScale = 0.2 # TODO: TESTING ONLY
originalWidth = int(image.shape[1] * sizeScale)# TODO: TESTING ONLY
originalHeight = int(image.shape[0] * sizeScale)# TODO: TESTING ONLY
#Resize image with a scale of 0.5 (above) but preserves aspect ratio# TODO: TESTING ONLY
resized = cv2.resize(image, (originalWidth, originalHeight), interpolation = cv2.INTER_AREA)# TODO: TESTING ONLY
