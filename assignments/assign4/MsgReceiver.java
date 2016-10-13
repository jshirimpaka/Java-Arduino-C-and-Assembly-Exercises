package assign4;

import studio4.SerialComm;


import java.io.*;

public class MsgReceiver {


	final private ViewInputStream vis;

	public MsgReceiver(InputStream in) {
		vis = new ViewInputStream(in);
	}

	public void run() throws IOException {
		// insert code here
		// read from vis and write to console

		int x = 0;
		@SuppressWarnings("unused")

		int r = 0;
		int t=0;
		int pot,pot1,pot2=0;
		int rawData,rawData1,rawData2=0;
		float UnfiltTemp,UnfiltTemp1,UnfiltTemp2,UnfiltTemp3,UnfiltTemp4=0;
		float filtTemp,filtTemp1,filtTemp2,filtTemp3,filtTemp4=0;
		
		while (true) {
			if(vis.available()>0){

				/* try {x = vis.available();
                } catch (Exception e) {
                       System.out.println("");
                }
                if (x > 0) {
				 */ 	
				//r= vis.read();
				//System.out.println(r);
				if(vis.read()==0x21){
					//System.out.println("!");
					if(vis.available()>0){
						switch(vis.read()){
						 
							case 0x30:
							 int length=vis.read();
							 String s="";
							 for(int i=0;i<length;i++){
								s+=(char)vis.read();
							 }
							 System.out.print(s);
							 System.out.println(": Debug message");

						     break;
						     
						case 0x31:
							System.out.println("Alarm");
							break;
                         
						case 0x32:
							
							t+=vis.read()<<24;
							t+=vis.read()<<16;
							t+=vis.read()<<8;
							t+=vis.read()<<0;

							System.out.println(t+ ": seconds");


						break;
						
						case 0x33:
							pot1=vis.read()<<8;
							pot2=vis.read()<<0;
							pot=pot1+pot2;
							
							System.out.println(pot+ ": Potentiometer Reading");
							
							break;
							
						case 0x34:
							rawData1=vis.read()<<8;
							rawData2=vis.read()<<0;
							rawData=rawData1+rawData2;
							
							System.out.println(rawData+ ": raw Temp Reading");
							
							break;
							
						case 0x35:
							
							UnfiltTemp1=(char)vis.read();
							UnfiltTemp2=(char)vis.read();
							UnfiltTemp3=(char)vis.read();
							UnfiltTemp4=(char)vis.read();
							UnfiltTemp=UnfiltTemp1+UnfiltTemp2+UnfiltTemp3+UnfiltTemp4;
							
                            System.out.println(UnfiltTemp/10+ ": degree C, unifilted temp");
							
							break;
							
                        case 0x36:
							
							filtTemp1=(char)vis.read();
							filtTemp2=(char)vis.read();
							filtTemp3=(char)vis.read();
							filtTemp4=(char)vis.read();
							filtTemp=filtTemp1+filtTemp2+filtTemp3+filtTemp4;
							
                            System.out.println(filtTemp/10+ ": degree C, filted temp");
							
							break;
							
                       
                        	
						}
					}
				}

			}

		}
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try
		{        	
			SerialComm s = new SerialComm();
			s.connect("COM3"); 
			InputStream in = s.getInputStream();
			MsgReceiver msgr = new MsgReceiver(in);
			msgr.run();
		}
		catch ( Exception e )
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
