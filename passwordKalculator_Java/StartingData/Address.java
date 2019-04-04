package StartingData;
import Exception.MyException;
public class Address extends StartingData{
	private String streetName;
	private String streetNumber;
	private String town;
	
	
    public Address(String strNam, String strNum, String t){
		super(3);//id di Address è 3;
		streetName = strNam;
		streetNumber = strNum;
		town = t;
	}
	
	public void setStreetName(String s){
		streetName=s;
	}
    public void setStreetNumber(String s){
		streetNumber=s;
	}
    public void setTown(String s){
		town=s;
	}
    public String getStreetName(){
		return streetName;
	}
    public String getStreetNumber(){
		return streetNumber;
	}
    public String getTown(){
		return town;
	}
	@Override
    public String getData(){
		return streetName+streetNumber+town;
	}
	@Override
    public boolean checkLength() throws MyException{
		if(streetName.length()<3 || town.length()<3)
			throw new MyException("I campi utilizzati per calcolare la password,\ndevono essere lunghi almeno 3 caratteri");
		String s="0";
		if(streetNumber.length()<3)
			streetNumber = new String(new char[3-streetNumber.length()]).replace("\0", s) + streetNumber;
			//streetNumber = repeat(s,3-streetNumber.length()) + streetNumber;
		return true;
	}
	@Override
    public void validate() throws MyException{
		//tolgo spazi
		streetName=streetName.replaceAll( ".", "" );
		streetName=streetName.replaceAll("\\s+","");
		streetNumber=streetNumber.replaceAll("/","");
		streetNumber=streetNumber.replaceAll("\\s+","");
		town=town.replaceAll("\\s+","");
		checkLength();//meglio controllare la lunghezza dopo aver tolto gli spazi
		//controllo che non ci siano numeri o caratteri speciali
		if(!streetName.matches("[a-zA-Z]+")){//se nella stringa non ci sono solo minuscole o maiuscole
			throw new MyException("Via non valida,\nsono consentite solo lettere");
		}
		if(!streetNumber.matches("[0-9]+")){//se nella string non ci sono solo numeri
			throw new MyException("N.Civico non valido,\nsono consentiti solo numeri");
		}
		if(!town.matches("[a-zA-Z]+")){//se non ci sono solo minuscole o maiuscole
			throw new MyException("Comune non valida,\nsono consentite solo lettere");
		}
	}
	
}