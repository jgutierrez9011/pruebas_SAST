public class BadArraySizeValidation {

    private static void die(String msg) {
        throw new RuntimeException(msg);
    }

    private static void buildList(int untrustedListSize) {
        if (0 > untrustedListSize) {
            die("Negative value supplied for list size, die evil hacker!");
        }
        Widget[] list = new Widget[untrustedListSize];
        list[0] = new Widget();
    }

    public static void main(String[] args) {
        buildList(0);
    }

    static class Widget {
        public Widget() {}
    }
}
