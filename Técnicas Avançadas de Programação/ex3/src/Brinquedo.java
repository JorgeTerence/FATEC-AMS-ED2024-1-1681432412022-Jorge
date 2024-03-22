public class Brinquedo {
  private int id;
  private String name;
  private String description;
  private double price;

  public Brinquedo(int id, String name, String description, double price) {
    this.id = id;
    this.name = name;
    this.description = description;
    this.price = price;
  }

  public void include() {
    System.out.println("Incluindo brinquedo");
  }

  public void show() {
    System.out.println("Código: " + this.id);
    System.out.println("Nome: " + this.name);
    System.out.println("Descrição: " + this.description);
    System.out.println("Preço: " + this.price);
  }

  public void setId(int id) {
    this.id = id;
  }

  public int getId() {
    return this.id;
  }

  public void setName(String name) {
    this.name = name;
  }

  public String getName() {
    return this.name;
  }

  public void setDescription(String description) {
    this.description = description;
  }

  public String getDescription() {
    return this.name;
  }

  public void setPrice(double price) {
    this.price = price;
  }

  public double getPrice() {
    return this.price;
  }
}
