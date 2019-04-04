package StartingData;
import Exception.MyException;
public class Date extends StartingData{
	private String day;
	private String month;
	private String year;
	
    public Date(String d, String m, String y){
		super(2);
		day=d;
		month=m;
		year=y;
	}
	public String getDay(){
    return day;
	}
	public String getMonth(){
		return month;
	}
	public String getYear(){
		return year;
	}
	//mancherebbero i set ma non li uso mai
	@Override
	public String getData(){
		return day+month+year;
	}
	@Override
    public boolean checkLength() throws MyException{
		if((day+month+year).length()!=8)//mantenendo gli zeri davanti al giorno e al mese
			throw new MyException("errore lunghezza data");
		return true;
	}
	@Override
    public void validate() throws MyException{
		//tolgo spazi
		day=day.replaceAll("\\s+","");
		month=month.replaceAll("\\s+","");
		year=year.replaceAll("\\s+","");
		checkLength();//meglio controllare la lunghezza dopo aver tolto gli spazi
		//controllo che non ci siano numeri o caratteri speciali
		if(!day.matches("[0-9]+")){//se non ci sono solo numeri
			throw new MyException("Giorno non valido,\nsono consentiti solo numeri");
		}
		if(!month.matches("[0-9]+")){//se non ci sono solo numeri
			throw new MyException("Mese non valido,\nsono consentiti solo numeri");
		}
		if(!year.matches("[0-9]+")){//se non ci sono solo numeri
			throw new MyException("Anno non valido,\nsono consentiti solo numeri");
		}
	}
}