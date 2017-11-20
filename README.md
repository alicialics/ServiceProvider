# cs200
https://github.com/zhuoli99/cs200

Github desktop software: https://desktop.github.com/

Manager class keeps track of logged in user and all available data ( user services ) and handles actions of user interface.
when you add new services to the program , you should also add them to Manager class.

Step is the state of the user interface, there are four steps in our program.For example, step 0 is the home page, step 1 is the main menu, step 2 is buyer page, step 3 is seller page.

In each step, user can choose to take actions, which takes them to next step.
For example, in step 0 , user can choose createAccount or signIn... Graph below shows all step and action relationships.

![img_1149](https://user-images.githubusercontent.com/31378877/32998511-9d6b7de0-cd50-11e7-84cf-4a7b5ddf4600.JPG)

Graph below is the output screenshot.

![screen shot 2017-11-19 at 5 32 22 pm](https://user-images.githubusercontent.com/31378877/32998473-2e9152a0-cd50-11e7-8d17-38279481cf27.png)

# Sqlite 
introduction: http://sqlite.org/

Sqlite3 is a database to save, retrieve and update data.

Sqlite3 Tutorial: https://www.codecademy.com/learn/learn-sql

Sqlite3 C++ interface: https://www.tutorialspoint.com/sqlite/sqlite_c_cpp.htm

In order to save our class data like user information and updated service information, we need to include this tool to our project.

I've written a sample class on how to use it.

Setup instructions are below:

Xcode: https://www.appcoda.com/sqlite-database-ios-app-tutorial/

Visual Studio: https://dcravey.wordpress.com/2011/03/21/using-sqlite-in-a-visual-c-application/

