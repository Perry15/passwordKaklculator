package Exception;
public class MyException extends Exception{
	
    public MyException(String error){
		super(error);
	}
	public String getError(){
		return this.getMessage();
	}
}