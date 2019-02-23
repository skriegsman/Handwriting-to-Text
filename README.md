# Picture-to-Braille
* ## Inspiration
  * We were inspired to build this after Saad complained about the cost of printing in color at the library to which our other friend said at least you're not printing in braille. As it turns out small braille printers can cost upwards of $1500; ours (with some more fine tuning) could be made in a factory for roughly $50. We also decided to add a feature to convert pictures of text to braille allowing blind students to translate over text books or school papers that come in english to braille.

* ## What it does
  * This program will take a picture input of a paper whether it be mail, prescription medicine bottle, text book page for school, etc. and return the text it finds as braille.
  * This can be a great resource to blind students learning in an environment that isn't equipped to teach them as braille printers are often expensive and difficult to use
  * The idea is that in a classroom setting if students are reading a book in class, the teacher or fellow student can take pictures of the book and have them printed in braille.

* ## How we built it
  *  The computer vision component was made using pytesseract to recognize text in the image and openCV to do the image pre-processing that helps pytesseract to more accurately read the text. OpenCV will detect rotation of the text and align the text as it would appear normally, then it crops the image to fit the text eliminating a good amount of background noise. It also implements a Gaussian blur to smooth out edges and thicken up parts of the letters. The detected letters will then be sent to the printer.
  * The final string is then sent to an arduino car via a wifi chip and is printed out onto paper.
  * The final string is then sent to an Arduino which then reads the string and prints each character, space, and number in braille. The printer consists of an Arduino car that uses two DC motors to drive a servo motor across the paper. The servo will turn and press onto the paper leaving a small bump (the paper is on a soft surface. The sequence of driving and servo turns form a braille pattern.

* ## Challenges we ran into
  * Initially we were going to use either scikit-learn found [here](https://scikit-learn.org/stable/) or tensorflow with keras found [here](https://keras.io/) in order to build a template of each letter. Then we would use openCV's built in matchTemplate() function. We found thousands of training images online but soon realized that the time to train it was going to be huge as we only had laptops.
  * Sam then found we could use pytesseracts built in method image_to_string to convert the picture to a paragraph format. Once we started using this method we had to work on processing the image so that it could be read accurately. We tried using TextBlob as an autocorrect function that would take misspelled words that pytsseract couldn't understand and correct them. However, it ended up overcorrecting small one letter words and messing up names or uncommon words.
  * Currently the Arduino car doesn't not receive a string from the computer over wifi like planned. Instead, it receives signals from an IR remote telling it to make individual letters depending on what button is pressed.

* ## Accomplishments that we're proud of
  * We are very proud that we were able to get such a high accuracy with this program. We still need to add in functionallity that will ignore images, and apply a blur based on how crisp the image is to start.
  * I calculated an accuracy of 99.54887218 percent in the large harry potter image, an accuracy of 98.987341772 percent in skew1, and an accuracy of 97.560975609 percent in shinyPaper. Certain pictures give us issues such as ones that have very small text, or text that has a significant blur or shadow to it.

* ## What we learned
  * We learned a lot about the importance of pre-processing the images. The goal is to make the final image you feed into tesseract as similar as possible so you get consistent results. This is why we align and crop every photo so that it is easy to read and there is no noise. We also apply a blur to the image to smooth out complex fonts that might confuse it.

* ## What's next for Picture-to-Braille
  * We would like to make this program into an app in the future. The app will connect to a printer over the internet to print any given pdf, photo, document, etc.
  * The printer would be made into a real product that can be mass-produced, not just a thrown together assortment of stuff. The goal would be to make it for less than $50 so it can be affordable to most people.
  * The final product type of idea would be a smart wifi enabled printer you could buy from staples for a relatively low cost that when sent a text document to print would automatically convert it to braille and print it out.

# Notes and Tutorials
* ## pytesseract:
  * ### What it is:
    * "Python-tesseract is an optical character recognition (OCR) tool for python. That is, it will recognize and “read” the text embedded in images. Python-tesseract is a wrapper for Google’s Tesseract-OCR Engine." ([Source](https://pypi.org/project/pytesseract/))
  * ### Installation
    * pip install pytesseract
    * install tesseract-OCR from an exe (if on windows) found [here](https://github.com/tesseract-ocr/tesseract/wiki)
  * ### Helpful Links:
    * Command Line Usage of pytesseract: https://github.com/tesseract-ocr/tesseract/wiki/Command-Line-Usage
    * How to train pytesseract: https://github.com/tesseract-ocr/tesseract/wiki/TrainingTesseract-4.00
    * Create training files to add handwritten fonts: http://trainyourtesseract.com/thankyou
    * Good source of handwritten fonts: https://www.1001fonts.com/handwritten-fonts.html

* ## OpenCV:  
  * ### What it is:
    * OpenCv is a free to use (under a BSD license) library for computer vision. It supports C++, Java, and python. It provides tools for image processing, recognition, and is used for everything from advanced robotics to deep learning facial recognition.
  * ### Installation:
    * pip install opencv-contrib-python
    * pip install numpy
  * ### Helpful Links:
    * [OpenCV Tutorial](https://docs.opencv.org/3.4/d8/d4b/tutorial_py_knn_opencv.html)
    * [OpenCV Text Detection Example](https://www.pyimagesearch.com/2018/08/20/opencv-text-detection-east-text-detector/)
