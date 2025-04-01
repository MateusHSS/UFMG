package dcc603.construtora;

import java.util.ArrayList;

public class EngenheiroSupervisor extends Engenheiro {
	private ArrayList<Engenheiro> supervisionados;

	public ArrayList<Engenheiro> getSupervisionados() {
		return supervisionados;
	}

	public void setSupervisionados(ArrayList<Engenheiro> supervisionados) {
		this.supervisionados = supervisionados;
	}
	
	public void adicionarSupervisionado(Engenheiro engenheiro) {
		this.supervisionados.add(engenheiro);
	}
}
