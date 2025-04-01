/**
 * 
 */
package dcc603.construtora;

import java.util.ArrayList;
import java.util.UUID;

/**
 * @author Eduardo
 *
 * Atencao! Esta classe eh um esqueleto. 
 * Voce pode (e deve) mudar e ampliar sua implementacao.
 *
 */
public class Projeto {
	private UUID id;
	private String descricao;
	private ArrayList<Cliente> clientes;
	private Engenheiro responsavel;
	
	public static final int ABERTO = 1;
	public static final int FECHADO = 2;
	
	protected int status = ABERTO;
	
	public Projeto() {
		this.id = UUID.randomUUID();
	}
	
	public Projeto(String descricao) {
		this.id = UUID.randomUUID();
		this.descricao = descricao;
	}
	
	public boolean projetoFechadoCerto() {
		return (status == FECHADO);
	}

	public boolean projetoFechadoErrado() {
		return (status > 2);
	}

	public void fecharProjeto() {
		this.status = FECHADO;
	}

	public UUID getId() {
		return id;
	}

	public void setId(UUID id) {
		this.id = id;
	}

	public String getDescricao() {
		return descricao;
	}

	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}

	public ArrayList<Cliente> getClientes() {
		return clientes;
	}

	public void setClientes(ArrayList<Cliente> clientes) {
		this.clientes = clientes;
	}

	public int getStatus() {
		return status;
	}

	public void setStatus(int status) {
		this.status = status;
	}

	public Engenheiro getResponsavel() {
		return responsavel;
	}

	public void setResponsavel(Engenheiro responsavel) {
		this.responsavel = responsavel;
	}
	
	public void adicionarCliente(Cliente cliente) {
		this.clientes.add(cliente);
	}
}
