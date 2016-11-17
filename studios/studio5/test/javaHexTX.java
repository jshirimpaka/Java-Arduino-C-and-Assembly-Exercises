 package studio5.test;
 
import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;

import studio4.SerialComm;

public class javaHexTX {

public static void main(String[] args) {
	  SerialComm in = new SerialComm();
      
      try {in.connect("COM3");
     
      } catch (Exception e){
             System.out.println("no");
      }
      
      OutputStream thingout = in.getOutputStream();
      BufferedOutputStream newData=new BufferedOutputStream(thingout);
		@SuppressWarnings({ "unused", "resource" })
	  DataOutputStream wrapp=new DataOutputStream(newData);
		
	
	//BufferedStream os = new BufferedStream(wrapp);
	
	
		//String myString = "C";
	
	Thread thread=new Thread(){
		@Override public void run() {
			// wait after connecting, so the bootloader can finish
			try {Thread.sleep(1000); } catch(Exception e) {
				
			}
			
		
	  while(true){
		try {
			wrapp.write(1);
			wrapp.flush();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	    }
	   }
	};
       thread.start();

	}
}