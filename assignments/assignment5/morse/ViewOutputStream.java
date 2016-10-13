package assignment5.morse;

import java.io.*;

import javax.swing.JFrame;

import studio4.PrintStreamPanel;

public class ViewOutputStream extends FilterOutputStream {

    final private PrintStreamPanel psp;
    final private PrintStream ps;

    public ViewOutputStream(OutputStream out) {
        super(out);

        JFrame f = new JFrame("ViewInputStream");
		f.setBounds(100,100,250,250);
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
    
    public void write(int a) throws IOException {
		
        // TODO
        // use super.read() to access the next byte from the InputStream
        // also, you can use ps like System.out to print to the new window
    	
    	super.write(a);
    	String hex=datahex(a);
    	//String hexX = Integer.toHexString(x);
    	ps.println(hex);
    	
    	
    }

}
