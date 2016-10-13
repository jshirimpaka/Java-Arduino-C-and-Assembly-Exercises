package assignment5.morse;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;


import studio4.SerialComm;

public class SerialOutput {
  
  private static ViewOutputStream v;
  private static InputStream inV;

    public SerialOutput(OutputStream out, InputStream in) {
      v = new ViewOutputStream(out);
      inV=in;
    }
  
 
   
  
  public static void main(String[] args) {
	  
     
      try
      {         
        SerialComm s = new SerialComm();
        s.connect("COM3"); 
        
        System.out.println("Type somrthing:");
        
        OutputStream inn = s.getOutputStream();
        
        
        
        
        SerialOutput msgr = new SerialOutput(inn,System.in);
        
        int r=0;
        while(true){
        	if(inV.available()>0){
        	r=inV.read();
        	v.write(r);
        	}
        }
        
      }
      catch ( Exception e )
      {
        // TODO Auto-generated catch block
        e.printStackTrace();
      }

    }

  }
