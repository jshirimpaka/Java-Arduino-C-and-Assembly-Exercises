 package studio5.test;
import java.io.BufferedReader;
import java.io.IOException;
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
	@SuppressWarnings("unused")
	OutputStream thing = in.getOutputStream();
	@SuppressWarnings("unused")
	BufferedReader os = new BufferedReader(new InputStreamReader(System.in));
	
	
		int p = 0;
		try {
			System.out.println("Type a character");
			p = System.in.read();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
			while (p <= 31) {
				System.out.println("type something");
				try {
					p = System.in.read();
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}
			}
			System.out.println(p);
			
		}
	
	}