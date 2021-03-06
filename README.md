# Team Batata Repository 
Project: Access control to UFSC’s Refectory (RU) 
Course: Programacao C++ para Sistemas Embarcados 
Semester: 2017.1 
Professor: [Eduardo Augusto Bezerra, PhD.](http://gse.ufsc.br/bezerra/)  
Major: Electronic Engineering  
University: UFSC - Universidade Federal de Santa Catarina  


# Project Short Descpription
This project consists in develop an access control system to ufsc refectory. This system might work online and offline. 
A Leon3/Atlys board is used to store users using data structures, unlock the turnstile for authorized users and send data to host computer.
The host computer is a web server containing an SQL database of users and purchases, a web API with user interface to generate reports.
Users can have two accounts: One related to RFID RU card; and other related to their smartphone app. 
The smartphone app might be able to connect with the turnstile and the server, in order to grant acces to ru and get reports from server. 

For more information about this project, access [link](http://gse.ufsc.br/bezerra/?page_id=1983)

## Repository instructions
- Pull this remote repository before you start working in your local repository, sou you'll be always up to date.
- Every new feature or documentation has to be in a new branch.
- Commits are allowed in the branch you're working.
- Commit messages might be always written in english.
- Don't merge branches without group agreement.
- Double check your local file changes and git log before pushing it to remote repository.
- Comments are welcome to discuss changes in branches.

# Repository Structure
* master Branch  
├── README.md<br/>
├── Code merged
* pdt branch  
├── Documentation - Product Tree Diagram Documentation  
* requirements branch  
├── Documentation - Project Requirements Documentation  
* wbs branch  
├── Documentation - Work Breakdown Structure Documentation  
* schedule branch  
├── Documentation - Schedule Documentation  
* class_diagram branch  
├── Documentation - Class Diagram Documentation  
* usecase branch  
├── Documentation - Use Case Documentation  

|   Part of the project      |  Folders  |
| :---                       |:---           |       
| Android app or related     | AndroidHTTP, AndroidTCP, Android_screens, ServerTCP, full_app |
| Leon3/Atlys board          | Ru_board, libraries |
| Webserver/Raspberry Pi     | back-end, front-end |
| Documentation              | Documentation, sequence_diagram, test_plan |


~$ Team Batata
