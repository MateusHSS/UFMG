package dcc603.construtora;

public class Endereco {
	private String rua;
	private int numero;
	private String complemento;
	private String bairro;
	private String cidade;
	private String CEP;
	
	public String getRua() {
		return rua;
	}
	
	public void setRua(String rua) {
		this.rua = rua;
	}
	
	public int getNumero() {
		return numero;
	}
	
	public void setNumero(int numero) {
		this.numero = numero;
	}
	
	public String getComplemento() {
		return complemento;
	}
	
	public void setComplemento(String complemento) {
		this.complemento = complemento;
	}
	
	public String getBairro() {
		return bairro;
	}
	
	public void setBairro(String bairro) {
		this.bairro = bairro;
	}
	
	public String getCidade() {
		return cidade;
	}
	
	public void setCidade(String cidade) {
		this.cidade = cidade;
	}
	
	public String getCEP() {
		return CEP;
	}
	
	public void setCEP(String CEP) {
		this.CEP = CEP;
	}	
}
