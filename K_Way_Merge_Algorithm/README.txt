Project by :
Eden Sofir 315900019
Aviv Mor 316309103
---------------------------------------------------------------------------------------------------------------------------------------
Email to contact:
avivmo@mta.ac.il
edenso@mta.ac.il

--------------------------------------------------------------------------------------------------------------------------------
Project Readme file :

We will explain the project by describe each and every single component that we made and what is here purpose.

Prime main component: 
This component contains all the sub component. First we put the scrollPane so we can scroll the page when stry to minimize the window of the application. 
Inside the scroller their is a border pane that contains the header, body, left component.  


Header Component: 
This component is controlling all the loading of the file. 
The ‘open file’ is a button that open the file dialogue and show the user only the file that has a ‘FXML’ ending , 
so we can minimize the possibility that the user will load the wrong file.
After the user chooses the file he/she needs to press the button ‘Press to load’. 
When pressing this button the file that the user chose is being load,
and the labels under the ‘Open file’ shows the status of the  loading and the progress of the loading file in the progress bar.

A process bar is filled by using the task theme when we created a class called UiTask which has a 
collectDateFromXmlTask ​​class where consumers are received and a call method is run which performs the loading process by counting like the stock and quantity of users. 
Creating an object of this type is created in the MainLogic department that is responsible for all the relationship between the client interface domain and the engine of the trading system. 
In this wish under the collectDataFromXml method we produce the above object and send it with
a runnable method to a method that creates connectivity between the user interface and the engine and produces a 
new Treade for it.
The connectivity is done in the PrimeMainController class under a method called bindTaskToUiComponents which is wired between the various 
labels on the screen and the loading process performed from the FXML file.

#Bonus Implementaion
In the upper right corner of the screen you can see the button aimed at the menu of switching themes. 
The theme replacement is divided into the default theme that is obtained when the application is opened, 
in addition to two other themes of darkness mode and light mode.
The themes are replaced in the code by changing the relevant StyleClass when you click on the onAction method of each of the themes buttons.



Left Component:
As soon as we click on the "press to load a file" button, a window will open on the left side of the screen describing the variety of different users.
On the left side of this component, the names of the users will appear vertically as separate units, 
which, when clicked, will present us with the various information for them.
In the component center, the user's name will appear at the beginning, followed by the value of the shares in his possession,
and then rubrics of the names of the shares in his possession will appear. 
Each rubric is an accordion container that each contains: the symbol of the above stock,
the amount of shares from that stock held by the specific user, 
the current stock value that is updated with the trading process in the system.
The linking for this component is done in the code below using links between the uploaded FXML file and where the names 
of the various information obtained from the file and the names within the different users are performed.
Updating of the various users, the quantities of shares held and the value of a particular share during the screen process 
is done through links between the engine which connects to a transaction created and updates at what price the share was purchased and updates the current share, 
updates the number of shares to the seller and the buyer The value of the total shares in his possession.

At the bottom of the window is a button that generates a new buy / sell order.
 At the click of a button a new window (popup window) will appear which will allow the customer to execute the following 
 trading order. I am required to follow the order in which the various information is entered, otherwise you will throw an 
 error at the customer in the information and do not fill in one of the various fields. Using the "Apply" button, the purchase 
 is made and displayed to the customer in the text box below all the information for the command executed by the customer. 
 When you click on the "Apply" button, a button will open at the bottom of the page that allows you to exit this window 
 and return to the main window for further trading.
 The link to the system engine from this window is made using an object of type "mainLogic" which as mentioned is responsible 
 for creating the connection between the user interface and the trading system engine. 
It is linked to the various parts of the "Engine" which produce a new command according to the data entered by the user.


Body Component:
In this component, the customer is presented with the variety of requests made from all users: 
lists of buying and selling shares, list of transactions made.
First, in order to view a list of a particular stock, you must select the desired stock in the combo-box window and when 
it is selected, a variety of trades will be opened and the orders that are waiting to be executed. 
Each list will open an accordion rubric that will contain the application details. 
For sales orders the requests will appear in ascending order and for the purchase orders the requests will appear in 
descending order. Each accordion contains:
 the name of the initiator of the order,
 the stated price, 
 the amount of shares he wishes to buy / sell,
 the type of order LMT / MKT,
 and the exact date of execution of the order.
 
#Bonus Implementaion
Next to the combo box is a button called "chart" and is at the beginning of the program in disable mode. 
Only after selecting the desired stock that we want to watch will we be able to click on the "chart" button and 
immediately a new window will open in which the stock graph will appear according to the trading process and the 
fluctuations in the value of the specific stock. This graph is updated every time a new transaction is made, 
in which the price of the stock is updated and in each variable also in the table. 
All this is done using users who return the transaction execution part in the engine of the system and it is 
passed back to the liaison body (mainLogic) and through an object of the class this information can be accessed 
to update the graph of the current stock.



Mian classes:

mainLogic Class-
This department aims to be the intermediary between the trading system engine and the user interface. 
In fact, in order to access the various information in the system engine that we were required to obtain, 
such as: executing commands and executing certain transactions or information about stocks, 
we created methods whose function is to transmit information from the customer and perform the operation to which it was sent. 
The Relative Component. 
In fact, the department performs most of the main operations for setting up the system and receiving the information 
by loading the file using - collectDateFromXml or creating a new trade using "createTradeExe" or creating certain messages 
for the user to execute trading orders.


PrimMainController-
This class is responsible, among other things, for initializing the board at the beginning of the application.
 Makes the names of the various data such as stocks, users, lists of sales, purchases and trades, 
 updates of various labels on the main screen, connectivity when loading the information from the FXML file using the 
 "bindTaskToUIComponent" method. In addition, this department's role is, among other things, 
 to replace the themes by updating the StyleSheets file that the system uses.

