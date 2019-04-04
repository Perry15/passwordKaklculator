package Password;
import StartingData.StartingData;
import java.util.Random;
//import java.lang.String;
public class Lev3 extends Password{
	private final int lenMin;
	private String description;
	private Random generator;
	public Lev3(){
		super("0000000000",10);
		lenMin=6;
		generator = new Random(); 
		description="Una password di livello 3 contiene lettere minuscole, maiuscole, numeri"
					+ " e alcuni caratteri speciali; possiede una lunghezza minima pari a 10 caratteri.";
	}
	public Lev3(String p){
		super(p,p.length());
		lenMin=10;
		generator = new Random(); 
		description="Una password di livello 3 contiene lettere minuscole, maiuscole, numeri"
					+ " e alcuni caratteri speciali; possiede una lunghezza minima pari a 10 caratteri.";
	}
	public String getDescription(){
		return description;
	}
	public String combination1(StartingData d1, StartingData d2){
		//lev3 lunghezza minima 10 lettere minuscole e maiuscole e numeri
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
		//IMP! metterlo prima di aggiungere i charSpec sennò è [0-9a-z(tutti i charSpec)]+
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
		//se ci sono caratteri e numeri inserisco due caratteri speciali casuali in delle posizioni casuali
		if(ris.matches("[a-zA-Z0-9]+")){
			//inserisco due caratteri speciali casuali in delle posizioni casuali
			String charSpec="&!^$%/=?*+-#@";//13 caratteri speciali
			//siccome £ non veniva visualizzato nel command prompt l'ho sotituito con ^
			l = generator.nextInt(13) + 0;//tra zero e 13 escluso infatti 12+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + charSpec.substring(l,l+1) + ris.substring(r,ris.length());
			
			l = generator.nextInt(13) + 0;//tra zero e 13 escluso infatti 12+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + charSpec.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
	public String combination2(StartingData d1, StartingData d2){
		//lev3 lunghezza minima 10 lettere minuscole e maiuscole e numeri
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
		//IMP! metterlo prima di aggiungere i charSpec sennò è [0-9a-z(tutti i charSpec)]+
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
		//se ci sono caratteri e numeri inserisco due caratteri speciali casuali in delle posizioni casuali
		if(ris.matches("[a-zA-Z0-9]+")){
			//inserisco due caratteri speciali casuali in delle posizioni casuali
			String charSpec="&!^$%/=?*+-#@";//13 caratteri speciali
			//siccome £ non veniva visualizzato nel command prompt l'ho sotituito con ^
			l = generator.nextInt(13) + 0;//tra zero e 13 escluso infatti 12+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + charSpec.substring(l,l+1) + ris.substring(r,ris.length());
			
			l = generator.nextInt(13) + 0;//tra zero e 13 escluso infatti 12+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + charSpec.substring(l,l+1) + ris.substring(r,ris.length());
		}
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
	public String combination3(StartingData d1, StartingData d2){
		//lev3 lunghezza minima 10 lettere minuscole e maiuscole e numeri

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
		//IMP! metterlo prima di aggiungere i charSpec sennò è [0-9a-z(tutti i charSpec)]+
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
		//se ci sono caratteri e numeri inserisco due caratteri speciali casuali in delle posizioni casuali
		if(ris.matches("[a-zA-Z0-9]+")){
			//inserisco due caratteri speciali casuali in delle posizioni casuali
			String charSpec="&!^$%/=?*+-#@";//13 caratteri speciali
			//siccome £ non veniva visualizzato nel command prompt l'ho sotituito con ^
			l = generator.nextInt(13) + 0;//tra zero e 13 escluso infatti 12+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + charSpec.substring(l,l+1) + ris.substring(r,ris.length());
			
			l = generator.nextInt(13) + 0;//tra zero e 13 escluso infatti 12+1
			r = generator.nextInt(ris.length()+1) + 0;//tra 0 e ris.length()
			ris=ris.substring(0,r) + charSpec.substring(l,l+1) + ris.substring(r,ris.length());
		}
		
		setPassword(ris);//setto il campo pwd
		setLength(getPassword().length());//setto la lunghezza effettiva il campo len
		return ris;
	}
}