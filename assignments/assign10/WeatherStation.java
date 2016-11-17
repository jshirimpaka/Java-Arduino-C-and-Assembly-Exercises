package assign10;

import java.io.*;
import java.net.HttpURLConnection;
import java.net.URL;
import java.net.URLConnection;

import assign4.MsgReceiver;
import studio4.SerialComm;
import studio4.ViewInputStream;


public class WeatherStation {

	public static ViewInputStream vis;
	
	
	public static int pot=0;
	public static long currentTime=0;
	
	
	
	
    public static void main(String[] args) throws Exception {
    	SerialComm s = new SerialComm();
    	 
        try {s.connect("COM3");
       
        } catch (Exception e){
               System.out.println("no");
        }
  	@SuppressWarnings("unused")
  	OutputStream thingTosend = s.getOutputStream();
  	DataOutputStream out = new DataOutputStream(new BufferedOutputStream(thingTosend));
  	
  	
  	InputStream thingReceived = s.getInputStream();
  	vis=new ViewInputStream(thingReceived);
  	
        // Create a new instance of Weather Station

    	WeatherStation theWeather = new WeatherStation();
    	int r = 0;
		int t=0;
		int pot1,pot2=0;

        // Based on the name of the instance created above, call xx.sendGet().
        // This will test to the function we'll be creating below.
    while(true){
    	if(vis.available()>0){
		  if(vis.read()==0x21){
			//System.out.println("!");
			if(vis.available()>0){
				switch(vis.read()){
				 
		
				
				case 0x33:
					pot1=vis.read()<<8;
					pot2=vis.read()<<0;
					pot=pot1+pot2;
					
					//System.out.println(pot+ ": Potentiometer Reading");
					
					break;
	
				}
			}
		  }
    	}

	
    	   if(System.currentTimeMillis()-currentTime>60000){
        	   currentTime+=60000.0;	   
               //theWeather.sendGet();
               try {
            	   
                  
                   theWeather.sendGet();
                   
            	   out.writeChar(theWeather.sendGet());
            	   out.flush();
            	   
       		} catch (IOException e) {
       			// TODO Auto-generated catch block
       			e.printStackTrace();
       		}
       }

         
    }
    }

    private static boolean currentMillis() {
		// TODO Auto-generated method stub
		return false;
	}

	// HTTP GET request
    private char sendGet() throws Exception {

        // Create a string that contains the URL you created for Lopata Hall in Studio 10
    	// Use the URL that DOES NOT have the timestamp included.
        // Since we only need the current data (currently) you can use the API to exclude all of the excess blocks (REQUIRED).
        // Instructions to do that are here: https://darksky.net/dev/docs/forecast
        // Test this new URL by pasting it in your web browser. You should only see the information about the current weather.
        @SuppressWarnings("unused")
		
        // Create a new URL object with the URL string you defined above. Reference: https://docs.oracle.com/javase/7/docs/api/java/net/URL.html
        //String toChange=AddisAbbabaUrl;
        String lopataUrl="https://api.darksky.net/forecast/0a967d168283aa53cd485bd57bb9231d/38.649196,-90.306099";
        
        String fransiscoUrl="https://api.darksky.net/forecast/0a967d168283aa53cd485bd57bb9231d/37.7749,122.4194";
        String AddisAbbabaUrl="https://api.darksky.net/forecast/0a967d168283aa53cd485bd57bb9231d/8.9806,38.7578";
       
        URL theUrl=new URL(fransiscoUrl);
        //URL testUrl=new URL(test);
       //return URLConnection
       URLConnection urlConnect=theUrl.openConnection();

        // Follow the instructions in the URL API to open this connection.
        // Cast this to a HttpURLConnection and save it in a new HttpURLConnection object.
         HttpURLConnection obj=(HttpURLConnection)(urlConnect);
        		 
       

        // Use the HttpURLConnection API to setup the HttpURLConnection you defined above.
        // Reference: https://docs.oracle.com/javase/7/docs/api/java/net/HttpURLConnection.html
        // Set the request method.
         obj.setRequestMethod("GET");
       //  https://www.mkyong.com/java/how-to-send-http-request-getpost-in-java/

        // Set the request property "User-Agent" to the User-Agent you saw in Wireshark when you did the first exercise in studio.
        // Repeat the quick wireshark example if you've forgotten. It should be in the form "xxxxxxx/#.#"

        obj.setRequestProperty("User-Agent", "Mozilla/5.0");

        // To debug, get and print out the response code.
        int response=obj.getResponseCode();
        //System.out.print(response);

        // The rest of the code should be much more familiar.
        // Create an InputStream that gets the input stream from our HttpURLConnection object.
        InputStream thing=obj.getInputStream();
        

        // Wrap it in a DataInputStream
       
        DataInputStream wrap=new DataInputStream(thing);
       


        // Read a line and save it in a string

        String inputs = wrap.readLine();
        // Close the InputStream
        
      //System.out.print(inputs);

        // Using string manipulation tools, pull out the string between quotes after "icon:"
        // For example: "summary":"Clear","icon":"clear-day","nearestStormDistance":27
        // You should pull out JUST "clear-day"
        String icon="icon";
        int iconIndex=inputs.indexOf(icon);
        int L=icon.length()+3;
        int index0=iconIndex+L;
        String subinPuts=inputs.substring(index0,inputs.length());
        char a='\"';
       
        int indexF=subinPuts.indexOf(a);
        
      // System.out.print(subinPuts.indexOf(a));
        
       String myString = subinPuts.substring(0,indexF);
        
       //System.out.print(myString);
   
        // You will set this char (in a switch statement) to one of the 5 types of weather. (Nothing TODO here)
        
        char weatherChar = '\0';
        
            
        
        
        // Create a switch statement based on the string that contains the description (ex. clear-day)
        // The switch statement should be able to handle all 10 of the icon values from the API: https://darksky.net/dev/docs/response
        // If the value is any of the cloudy ones, set weatherChar to C
        // If the value is fog, set it to F
        // If the value if wind, set it to W
        // If the value is any of the clear ones, set it to S
        // If the value is any type of precipitation, set it to P
       
        switch(myString){
        
    	case "clear-day":
    		weatherChar='S';
    	
    	break;
    	
    	case "clear-night":
    		weatherChar='S';
    	
    	break;
    	
    	case "rain":
    		weatherChar='P';
    	
    	break;
    	
    	case "thunderstorm":
    		weatherChar='P';
    	
    	break;
    	
    	case "snow":
    		weatherChar='P';
    	
    	break;
    	case "sleet":
    		weatherChar='P';
    	break;
    	
    	case "wind":
    		weatherChar='W';
    	
    	break;
    	
    	case "tornado":
    		weatherChar='W';
    	
    	break;
    	
    	case "fog":
    		weatherChar='F';
    	
    	break;
    	
    	case "partly-cloudy-day":
    		weatherChar='C';
    	
    	break;
    	
    	case "partly-cloudy-night":
    		weatherChar='C';
    	
    	break;	
     }

    System.out.print(weatherChar);
	return weatherChar;  
        

       
        // Now you're ready to implement this into your past code to send it to the Arduino.
        // You also have to make a couple modifications to handle the switch location requests from Arduino.
        // Choose three locations or more, but make sure one is Lopata Hall.
        
       /* SerialComm in = new SerialComm();
        
        
        try {in.connect("COM3");
       
        } catch (Exception e){
               System.out.println("no");
        }
      	@SuppressWarnings("unused")
  	    OutputStream weatherThing = in.getOutputStream();
      	weatherChar= (char) System.in.read();*/
  	
    }
}