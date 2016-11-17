package studio4;

import java.io.BufferedInputStream;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.util.Enumeration;

//import gnu.io.CommPortIdentifier;
//import gnu.io.NoSuchPortException; 

import studio4.SerialComm;
 
public class SerialTestInput {
 
       public static void main(String[] args) {
    	   
    	   
             SerialComm in = new SerialComm();
             
            
             try {in.connect("COM3");
            
             } catch (Exception e){
                    System.out.println("no");
             }
            
            
          // SerialComm out = new SerialComm();
//            
//             try {out.connect("COM3");} catch (Exception e){
//                    System.out.println("no");
//             }
            
             InputStream thing = in.getInputStream();
             
            ViewInputStream Data=new ViewInputStream(thing);
			BufferedInputStream newData=new BufferedInputStream(Data);
			@SuppressWarnings({ "unused", "resource" })
			DataInputStream wrapp=new DataInputStream(newData);
             int x = 0;
             int r= 0;
             int pot=0;
             int pot1=0; int pot2=0;
             while (true) {
                    try {x = thing.available();
                    } catch (Exception e) {
                           System.out.println("");
                    }
                    if (x > 0) {
                          // try {r = thing.read() ;
                    	  // try {r=Data.read();
                    	        try{ r=wrapp.read(); 
                    	        //wrapp.readUTF()
                           } catch (Exception e) {
                                  System.out.println("");
                           }
                           //System.out.print(r);
                    	        pot1=r<<8;
    							pot2=r<<0;
    							pot=pot1+pot2;
                           System.out.print(pot);
                          
                           /* try {
							//System.out.println(Data.read());
                        	   System.out.println((char)wrapp.read()); 
                         	   
						} catch (IOException e) {
							System.out.println("");
						}*/
                    }
             }
            
            
       }
 
}