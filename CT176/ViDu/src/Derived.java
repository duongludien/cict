public class Derived extends Base {
	@Override
	public void show() {
		System.out.print("Derived is called" + super.y);
		super.show();
	}
}
