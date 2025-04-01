package dcc603.construtora;

import java.util.ArrayList;
import java.util.UUID;

public class Cliente {
	private UUID id;
	private String nome;
	private Endereco endereco;
	
	private ArrayList<Projeto> projetos;
	
	public Cliente() {
		this.id = UUID.randomUUID();
	}
	
	public Cliente(String nome) {
		this.id = UUID.randomUUID();
		this.nome = nome;
	}

	public UUID getId() {
		return this.id;
	}

	public void setId(UUID id) {
		this.id = id;
	}
	
	public String getNome() {
		return this.nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public Endereco getEndereco() {
		return this.endereco;
	}
	
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
	
	public void solicitarProjeto() {
		Projeto projeto = new Projeto();
		
		this.projetos.add(projeto);
		
		projeto.adicionarCliente(this);
	}
	
}
