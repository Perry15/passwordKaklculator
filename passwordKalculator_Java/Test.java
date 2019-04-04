import Exception.MyException;
import StartingData.*;
import Password.*;

public class Test {
    public static void main(String[] args){
		try{
			/*System.out.println("\n---------------NAMESURNAME---------------");
			StartingData namSur = new NameSurname("gio", "per");
			System.out.println("id: " + namSur.getId() + " nomeCognome istanziato: " + namSur.getData());
			namSur.checkLength();
			System.out.println("nomeCognome dopo checkLength: " + namSur.getData());
			namSur.validate();
			System.out.println("nomeCognome dopo validate: " + namSur.getData());
			System.out.println("\n------------------DATE-------------------");
			StartingData date = new Date("02", "12", "1948");
			System.out.println("id: " + date.getId() + " data istanziato: " + date.getData());
			date.checkLength();
			System.out.println("data dopo checkLength: " + date.getData());
			date.validate();
			System.out.println("data dopo validate: " + date.getData());
			System.out.println("\n-----------------ADDRESS-----------------");
			StartingData add = new Address("baf", "5", "Cam");
			System.out.println("id: " + add.getId() + " indirizzo istanziato: " + add.getData());
			add.checkLength();
			System.out.println("indirizzo dopo checkLength: " + add.getData());
			add.validate();
			System.out.println("indirizzo dopo validate: " + add.getData());
			System.out.println("\n-------------------WORD-------------------");
			StartingData word = new Word("Ferrari");
			System.out.println("id: " + word.getId() + " Parola istanziato: " + word.getData());
			word.checkLength();
			System.out.println("Parola dopo checkLength: " + word.getData());
			word.validate();
			System.out.println("Parola dopo validate: " + word.getData());
			System.out.println("\n------------------NUMBER------------------");
			StartingData num = new Numberr("5");
			System.out.println("id: " + num.getId() + " Numero istanziato: " + num.getData());
			num.checkLength();
			System.out.println("Numero dopo checkLength: " + num.getData());
			num.validate();
			System.out.println("Numero dopo validate: " + num.getData());*/
			
			StartingData d1 = new NameSurname("Gino", "Fastidio");
			//StartingData d2 = new Word("vento");
			StartingData d2 = new Numberr("15");
			//StartingData d2 = new Date("25","06","1997");
			System.out.println("D1 - id: " + d1.getId() + " data: " + d1.getData());
			System.out.println("D2 - id: " + d2.getId() + " data: " + d2.getData());
			//prima di usare gli oggetti StartingData bisogna sempre controllarli
			d1.checkLength();d1.validate();
			d2.checkLength();d2.validate();
			
			Password result0 = new Lev0();
			System.out.println("Descrizione: " +result0.getDescription());
			result0.combination1(d1,d2);
			System.out.println("COMBINATION1 - pwd:" + result0.getPassword() +" length: " +result0.getLength());
			result0.combination2(d1,d2);
			System.out.println("COMBINATION2 - pwd:" + result0.getPassword() +" length: " +result0.getLength());
			result0.combination3(d1,d2);
			System.out.println("COMBINATION3 - pwd:" + result0.getPassword() +" length: " +result0.getLength());
			Password result1 = new Lev1();
			System.out.println("Descrizione: " +result1.getDescription());
			result1.combination1(d1,d2);
			System.out.println("COMBINATION1 - pwd:" + result1.getPassword() +" length: " +result1.getLength());
			result1.combination2(d1,d2);
			System.out.println("COMBINATION2 - pwd:" + result1.getPassword() +" length: " +result1.getLength());
			result1.combination3(d1,d2);
			System.out.println("COMBINATION3 - pwd:" + result1.getPassword() +" length: " +result1.getLength());
			Password result2 = new Lev2();
			System.out.println("Descrizione: " +result2.getDescription());
			result2.combination1(d1,d2);
			System.out.println("COMBINATION1 - pwd:" + result2.getPassword() +" length: " +result2.getLength());
			result2.combination2(d1,d2);
			System.out.println("COMBINATION2 - pwd:" + result2.getPassword() +" length: " +result2.getLength());
			result2.combination3(d1,d2);
			System.out.println("COMBINATION3 - pwd:" + result2.getPassword() +" length: " +result2.getLength());
			Password result3 = new Lev3();
			System.out.println("Descrizione: " +result3.getDescription());
			result3.combination1(d1,d2);
			System.out.println("COMBINATION1 - pwd:" + result3.getPassword() +" length: " +result3.getLength());
			result3.combination2(d1,d2);
			System.out.println("COMBINATION2 - pwd:" + result3.getPassword() +" length: " +result3.getLength());
			result3.combination3(d1,d2);
			System.out.println("COMBINATION3 - pwd:" + result3.getPassword() +" length: " +result3.getLength());
		}
		catch(MyException e){
			System.out.println("Eccezione: " + e.getError());
		}
		
	}
}