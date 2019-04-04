package Password;
import StartingData.StartingData;
import java.util.Random;
//import java.lang.String;
public class Lev2 extends Password{
	private final int lenMin;
	private String description;
	private Random generator;
	public Lev2(){
		super("00000000",8);
		lenMin=6;
		generator = new Random(); 
		description="Una password di livello 2 contiene lettere minuscole, maiuscole e numeri;"
					+ " possiede una lunghezza minima pari a 8 caratteri";
	}
	public Lev2(String p){
		super(p,p.length());
		lenMin=8;
		generator = new Random(); 
		description="Una password di livello 2 contiene lettere minuscole, maiuscole e numeri;"
					+ " possiede una lunghezza minima pari a 8 caratteri";
	}
	public String getDescription(){
		return description;
	}
	public String combination1(StartingData d1, StartingData d2){
		//lev2 lunghezza minima 8 lettere minuscole e maiuscole e numeri
		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p=d1.getData().substring(r,r+3);
		//inserisco lettere maiuscole casuali
		r = generator.nextInt(3) + 0;//tra 0 e 2
		int x = generator.nextInt(3-r) + 1;//# lettere maiuscole casuale
		String ris=p.substring(0,r)+p.substring(r,r+x).toUpperCase()+p.substring(r+x,3);
		
		l = d2.getData().length();//l di d2
		r = generator.nextInt(l-2) + 0;
		p = d2.getData().substring(r,r+3);
		ris+=p;

		l = d1.getData().length();//l di d1
		r = generator.nextInt(l-2) + 0;
		p = d1.getData().substring(r,r+3);
		//inserisco lettere maiuscole casuali
		r = generator.nextInt(3) + 0;//tra 0 e 2
		x = generator.nextInt(3-r) + 1;//# lettere maiuscole casuale
		ris+=p.substring(0,r)+p.substring(r,r+x).toUpperCase()+p.substring(r+x,3);

		//se non ci già numeri li aggiungo
		if(ris.matches("[a-zA-Z]+")){//se ci sono solo lettere devo aggiungere i numeri
			r=generator.nextInt(100-10) + 10;//-10 perchè facendo + 10 aggiungo 10 anche al massimo
			ris+=String.valueOf(r);
		}
		//se mancano lettere minuscole o maiuscole, sono tutti numeri e forse maiuscole [0-9A-Z]+
		//oppure sono tutti numeri e forse minuscole [0-9a-z]+
		if(ris.matches("[0-9A-Z]+") || ris.matches("[0-9a-z]+")){//se non ci sono lettere
			//aggiungo 2 lettere casuali una minuscola e una maiuscola
			String alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
			
			String alf2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf2.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
	public String combination2(StartingData d1, StartingData d2){
		//lev2 lunghezza minima 8 lettere minuscole e maiuscole e numeri
		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p=d1.getData().substring(r,r+3);
		//inserisco lettere maiuscole casuali
		r = generator.nextInt(3) + 0;//tra 0 e 2
		int x = generator.nextInt(3-r) + 1;//# lettere maiuscole casuale
		p=p.substring(0,r)+p.substring(r,r+x).toUpperCase()+p.substring(r+x,3);
		String ris=inversion(p);
		
		l = d2.getData().length();//l di d2
		r = generator.nextInt(l-2) + 0;
		p = d2.getData().substring(r,r+3);
		ris+=inversion(p);

		l = d1.getData().length();//l di d1
		r = generator.nextInt(l-2) + 0;
		p = d1.getData().substring(r,r+3);
		//inserisco lettere maiuscole casuali
		r = generator.nextInt(3) + 0;//tra 0 e 2
		x = generator.nextInt(3-r) + 1;//# lettere maiuscole casuale
		p = p.substring(0,r)+p.substring(r,r+x).toUpperCase()+p.substring(r+x,3);
		ris+=inversion(p);

		//se non ci già numeri li aggiungo
		if(ris.matches("[a-zA-Z]+")){//se ci sono solo lettere devo aggiungere i numeri
			r=generator.nextInt(100-10) + 10;//-10 perchè facendo + 10 aggiungo 10 anche al massimo
			ris+=String.valueOf(r);
		}
		//se mancano lettere minuscole o maiuscole, sono tutti numeri e forse maiuscole [0-9A-Z]+
		//oppure sono tutti numeri e forse minuscole [0-9a-z]+
		if(ris.matches("[0-9A-Z]+") || ris.matches("[0-9a-z]+")){//se non ci sono lettere
			//aggiungo 2 lettere casuali una minuscola e una maiuscola
			String alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
			
			String alf2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf2.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
	public String combination3(StartingData d1, StartingData d2){
		//LEV2 LUNGHEZZA MINIMA 8 LETTERE MINUSCOLE E MAIUSCOLE E NUMERI
		//nella moltiplicazione la password formata da 3 gruppi p1, p2, p3
		//(dei quali p1 e p2 possiedono dei caratteri maiuscoli inseriti a caso)
		//viene divisa in 2 gruppi e i caratteri di questi vengono alternati
		//siccome la lunghezza è 9 dipsari il carattere centrale rimane fisso

		int l=d1.getData().length();
		int r=generator.nextInt(l-2) + 0;
		String p=d1.getData().substring(r,r+3);
		//inserisco lettere maiuscole casuali
		r = generator.nextInt(3) + 0;//tra 0 e 2
		int x = generator.nextInt(3-r) + 1;//# lettere maiuscole casuale
		String tmp=p.substring(0,r)+p.substring(r,r+x).toUpperCase()+p.substring(r+x,3);
		
		l = d2.getData().length();//l di d2
		r = generator.nextInt(l-2) + 0;
		p = d2.getData().substring(r,r+3);
		tmp+=p;

		l = d1.getData().length();//l di d1
		r = generator.nextInt(l-2) + 0;
		p = d1.getData().substring(r,r+3);
		//inserisco lettere maiuscole casuali
		r = generator.nextInt(3) + 0;//tra 0 e 2
		x = generator.nextInt(3-r) + 1;//# lettere maiuscole casuale
		tmp+=p.substring(0,r)+p.substring(r,r+x).toUpperCase()+p.substring(r+x,3);
		//a questo devo creare la stringa alternata
		String ris="";
		int k,n=tmp.length();
		if(n%2==0)//se è pari ma in lev0 sarà sempre pari perchè 3+3=6
			k=0;//la costante è 0
		else//se la lunghezza è dispari
			k=1;//k è 1 perchè lo aggiungo al primo parametro della mid in modo da
			//tenere un carattere centrale fermo in ris (di solito lunga 9)
		for(int i=0;i<n/2;++i){
			ris+=tmp.substring(i,i+1)+tmp.substring(i+(n/2)+k,(i+(n/2)+k)+1);
		}
		if(k==1){//se la lunghezza era dispari
			//aggiungo il carattere centrale: tmp.substring(n/2,(n/2)+1) 
			//nella pos centrale di ris
			ris=ris.substring(0,n/2) + tmp.substring(n/2,(n/2)+1) + ris.substring(n/2,n-1);
		}

		//se non ci già numeri li aggiungo
		if(ris.matches("[a-zA-Z]+")){//se ci sono solo lettere devo aggiungere i numeri
			r=generator.nextInt(100-10) + 10;
			ris+=String.valueOf(r);
		}
		//se mancano lettere minuscole o maiuscole, sono tutti numeri e forse maiuscole [0-9A-Z]+
		//oppure sono tutti numeri e forse minuscole [0-9a-z]+
		if(ris.matches("[0-9A-Z]+") || ris.matches("[0-9a-z]+")){//se non ci sono lettere
			//aggiungo 2 lettere casuali una minuscola e una maiuscola
			String alf="abcdefghijklmnopqrstuvwxyz";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf.substring(l,l+1) + ris.substring(r,ris.length());
			
			String alf2="ABCDEFGHIJKLMNOPQRSTUVWXYZ";//26 lettere
			l = generator.nextInt(26) + 0;//tra zero e 26 escluso infatti 25+1
			r = generator.nextInt(ris.length()+1)+ 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + alf2.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
}