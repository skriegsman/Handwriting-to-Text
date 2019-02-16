# Picture-to-Braille

* ## Inspiration

* ## What it does
  * This program will take a picture input of a paper whether it be mail, prescription medicine bottle, text book page for school, etc. and return the text it finds as braille.
  * This can be a great resource to blind students learning in an environment that isn't equipped to teach them as braille printers are often expensive and difficult to use
  * The idea is that in a classroom setting if students are reading a book in class, the teacher or fellow student can take pictures of the book and have them printed in braille.
* ## How we built it
  *  The computer vision component was made using pytesseract to both refine images that are fed into the program and to identify letters in the picture.
  * Then the string of text identified by pytesseract is fed into TextBlob. TextBlob acts as an autocorrect feature and corrects typos or misidentified letters in the String
  * The final string is then sent to an arduino car via a wifi chip and is printed out onto paper.
* ## Challenges we ran into

* ## Accomplishments that we're proud of

* ## What we learned

* ## What's next for Picture-to-Braille

# Notes and Tutorials
* ## OpenCV:  pip install opencv-contrib-python
  * ### What it is:
  * ### Links:
    * (https://docs.opencv.org/3.4/d8/d4b/tutorial_py_knn_opencv.html) [OpenCV Tutorial]
    * [https://www.pyimagesearch.com/2018/08/20/opencv-text-detection-east-text-detector/] (OpenCV Text Detection Example)
* ## SciKit:
  * ### What it is:
  * ### Links:
    * https://scikit-learn.org/stable/
* ## Keras:
  * ### What it is:
  * ### How to Install:
    * DO NOT INSTALL IN WINDOWS
    * Use [] (Docker) to contain the Tensorflow and Keras mess of programs
  * ### Links:
    * [https://nextjournal.com/gkoehler/digit-recognition-with-keras] (Handwriting Recognition Example)
