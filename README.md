I. C++ Repository Service

  1. To run this service, you need build the EventRepository project. You can import it in Visual Studio, or build it using msbuild.
  2. To run the project, go to the $(project location)/Debug(or Release) and then you have 2 options:
  
      a. Start the server for repository service. In this case, the project will run as a server waiting for requests from the Java service. For this, run the command:
        
             EventsRepository.exe start_server
          
      b. Print all the events stored in the repository file. For this, run the command:
      
              EventsRepository.exe print_events
            
     NOTE: This service works only for Windows OS.
              
II. Java EventsService

  1. First, you need to build the project using Maven. Maven installation tutorial: https://maven.apache.org/install.html
  2. You can run the project in your IDE, or go to $(project location)/target and run the command:
      
              java -jar eventsService-0.0.1-SNAPSHOT.jar
  
  
Also, in the target folder I've already added the exe and the jar files. If you don't want to build the projects, you can try to run them.

    

