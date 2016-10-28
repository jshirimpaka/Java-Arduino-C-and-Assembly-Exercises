package studio8.Acceleration;

import java.io.*;

import java.io.BufferedReader;

import java.io.FileNotFoundException;

import java.io.FileReader;

import java.io.IOException;

public class CountSteps {



	public static void main(String[] args) {

		String csvFile="studios/studio8/Acceleration/data.csv";

		String line = "";

		String cvsSplitBy=",";

		try{FileReader fr = new FileReader(csvFile);

		BufferedReader br = new BufferedReader(fr);

		while((line=br.readLine()) != null) {

			String[] country = line.split(cvsSplitBy);

			System.out.println("x="+country[0]+"y="+country[1]+"z="+country[2]);

		}

		}

		catch(IOException e){

			e.printStackTrace();

		}
		}

}

