package studio4;

import java.io.*;

public class ViewInputStream extends FilterInputStream {

    final private PrintStreamPanel psp;
    final private PrintStream ps;

    public ViewInputStream(InputStream in) {
        super(in);

        psp = new PrintStreamPanel();
        ps = psp.getPrintStream(); 
    }

    public int read() throws IOException {
		
        // TODO
        // use super.read() to access the next byte from the InputStream
        // also, you can use ps like System.out to print to the new window
    	
    	int x=super.read();
    	//String hexX = Integer.toHexString(x);
    	ps.println(x);
    	
    	return x;
    }

}
