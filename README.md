# Picture-to-Braille

* ## Inspiration
  * We were inspired by .....
* ## What it does
  * This program will take a picture input of a paper whether it be mail, prescription medicine bottle, text book page for school, etc. and return the text it finds as braille.
  * This can be a great resource to blind students learning in an environment that isn't equipped to teach them as braille printers are often expensive and difficult to use
  * The idea is that in a classroom setting if students are reading a book in class, the teacher or fellow student can take pictures of the book and have them printed in braille.
* ## How we built it
  *  The computer vision component was made using pytesseract to both refine images that are fed into the program and to identify letters in the picture.
  * Then the string of text identified by pytesseract is fed into TextBlob. TextBlob acts as an autocorrect feature and corrects typos or misidentified letters in the String
  * The final string is then sent to an arduino car via a wifi chip and is printed out onto paper.
* ## Challenges we ran into
  * Initially we were going to use either scikit-learn found [here](https://scikit-learn.org/stable/) or tensorflow with keras found [here](https://keras.io/) in order to build a template of each letter. Then we would use openCV's built in matchTemplate() function. We found thousands of training images online but soon realized that the time to train it was going to be huge as we only had laptops.
* ## Accomplishments that we're proud of 

* ## What we learned

* ## What's next for Picture-to-Braille
  * We would like to make this program into an app in the future. The app will connect to a printer over the internet to print any given pdf, photo, document, etc.
  * The printer would be made into a real product that can be mass-produced, not just a thrown together assortment of stuff. The goal would be to make it for less than $50 so it can be affordable to most people.
# Notes and Tutorials
* ## pytesseract:
  * ### What it is:
  * ### Installation
    * pip install pytesseract
    * install tesseract-OCR from an exe found [here](https://github.com/tesseract-ocr/tesseract/wiki)
  * ### Links:

* ## TextBlob:
  * ### What it is:
  * ### Installation
  * ### Links:
* ## OpenCV:  
  * ### What it is:
  * ### Installation:
    * pip install opencv-contrib-python
  * ### Links:
    * [OpenCV Tutorial](https://docs.opencv.org/3.4/d8/d4b/tutorial_py_knn_opencv.html)
    * [OpenCV Text Detection Example](https://www.pyimagesearch.com/2018/08/20/opencv-text-detection-east-text-detector/)
