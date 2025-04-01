package dcc603.construtora;

import java.util.ArrayList;
import java.util.UUID;

public class Engenheiro {
	private UUID id;
	private String nome;
	private Engenheiro supervisor;
	
	private ArrayList<Projeto> projetos;
	
	public Engenheiro() {
		this.id = UUID.randomUUID();
	}
	
	public UUID getId() {
		return id;
	}
	
	public void setId(UUID id) {
		this.id = id;
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public Engenheiro getSupervisor() {
		return supervisor;
	}
	
	public void setSupervisor(Engenheiro supervisor) {
		this.supervisor = supervisor;
	}
	
	public ArrayList<Projeto> getProjetos() {
		return this.projetos;
	}
	
	public void setProjetos(ArrayList<Projeto> projetos) {
		this.projetos = projetos;
	}
	
	public void adicionarProjeto(Projeto projeto) {
		this.projetos.add(projeto);
	}
}
