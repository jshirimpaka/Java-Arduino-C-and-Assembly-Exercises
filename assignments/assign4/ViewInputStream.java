package assign4;

import java.io.*;

import javax.swing.JFrame;
import studio4.PrintStreamPanel;

public class ViewInputStream extends FilterInputStream {

    final private PrintStreamPanel psp;
    final private PrintStream ps;

    public ViewInputStream(InputStream in) {
        super(in);
        JFrame f = new JFrame("ViewInputStream");
		f.setBounds(100,100,1000,1000);
        psp = new PrintStreamPanel();
		f.getContentPane().add(psp);
		f.setVisible(true);
        ps = psp.getPrintStream(); 
        
        
    }
    
    public static String datahex(int nberD) {
        String charTouse = "0123456789ABCDEF";
        if (nberD <= 0) return "0";
        int base = 16;   
        String hex = "";
        while (nberD > 0) {
            int digit = nberD % base;             
            hex = charTouse.charAt(digit) + hex;  
            nberD = nberD/ base;
        }
        return hex;
        
    }
    
    public int read() throws IOException {
        // TODO
        // use super.read() to access the next byte from the InputStream
        // also, you can use ps like System.out to print to the new window
    	int x=super.read();
        //String hexX = Integer.toHexString(x);
        String hex=datahex(x);
        ps.println(hex);
        
        return x;
    }
    
}