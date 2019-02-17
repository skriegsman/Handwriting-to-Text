# Picture-to-Braille
* ## Inspiration
  * We were inspired to build this after Saad complained about the cost of printing in color at the library to which our other friend said at least your not printing in braille. As it turns out small braille printers can cost upwards of $1500, ours (with some more fine tuning) could be made in a factory for roughly $50. We also decided to add a feature to convert pictures of text to braille allowing blind students to translate over text books or school papers that come in english to braille.

* ## What it does
  * This program will take a picture input of a paper whether it be mail, prescription medicine bottle, text book page for school, etc. and return the text it finds as braille.
  * This can be a great resource to blind students learning in an environment that isn't equipped to teach them as braille printers are often expensive and difficult to use
  * The idea is that in a classroom setting if students are reading a book in class, the teacher or fellow student can take pictures of the book and have them printed in braille.

* ## How we built it
  *  The computer vision component was made using pytesseract to recognize text in the image and openCV to do the image pre-processing that helps pytesseract to more accurately read the text. OpenCV will detect rotation of the text and align the text as it would appear normally, then it crops the image to fit the text eliminating a good amount of background noise. It also implements a Gaussian blur to smooth out edges and thicken up parts of the letters. The detected letters will then be sent to the printer.
  * The final string is then sent to an arduino car via a wifi chip and is printed out onto paper.

* ## Challenges we ran into
  * Initially we were going to use either scikit-learn found [here](https://scikit-learn.org/stable/) or tensorflow with keras found [here](https://keras.io/) in order to build a template of each letter. Then we would use openCV's built in matchTemplate() function. We found thousands of training images online but soon realized that the time to train it was going to be huge as we only had laptops.
  * Sam then found we could use pytesseracts built in method image_to_string to convert the picture to a paragraph format. Once we started using this method we had to work on processing the image so that it could be read accurately. We tried using TextBlob as an autocorrect function that would take misspelled words that pytsseract couldn't understand and correct them. However, it ended up overcorrecting small one letter words and messing up names or uncommon words.

* ## Accomplishments that we're proud of
  *

* ## What we learned
  *

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

* ## OpenCV:  
  * ### What it is:
  * ### Installation:
    * pip install opencv-contrib-python
  * ### Helpful Links:
    * [OpenCV Tutorial](https://docs.opencv.org/3.4/d8/d4b/tutorial_py_knn_opencv.html)
    * [OpenCV Text Detection Example](https://www.pyimagesearch.com/2018/08/20/opencv-text-detection-east-text-detector/)
