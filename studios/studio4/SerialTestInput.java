package studio4;
import java.io.InputStream;
import java.util.Enumeration;
 
import gnu.io.CommPortIdentifier;
import gnu.io.NoSuchPortException;
import studio4.SerialComm;
 
public class SerialTestInput {
 
       public static void main(String[] args) {
             SerialComm in = new SerialComm();
            
             try {in.connect("COM3");
            
             } catch (Exception e){
                    System.out.println("no");
             }
            
            
             SerialComm out = new SerialComm();
            
             try {out.connect("COM3");} catch (Exception e){
                    System.out.println("no");
             }
            
             InputStream thing = in.getInputStream();
             int x = 0;
             int r = 0;
             while (true) {
                    try {x = thing.available();
                    } catch (Exception e) {
                           System.out.println("");
                    }
                    if (x > 0) {
                           try {r = thing.read() ;
                           } catch (Exception e) {
                                  System.out.println("");
                           }
                           System.out.println(r);
                    }
             }
            
            
       }
 
}
 