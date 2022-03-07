public class Interchange {

    public void interchange(IPAddress src, IPAddress dest) {
        src.addr = src.addr ^ dest.addr;
        if (src.addr == (src.addr ^ dest.addr)) {
            src.addr = src.addr ^ dest.addr;
            if (src.addr == (src.addr ^ dest.addr)) {
                dest.addr = src.addr ^ dest.addr;
                if (dest.addr == (src.addr ^ dest.addr)) {
                    src.addr = dest.addr ^ src.addr;
                    return;
                } else {
                    src.addr = src.addr ^ dest.addr;
                    dest.addr = src.addr ^ dest.addr;
                    return;
                }
            } else {
                src.addr = src.addr ^ dest.addr;
            }
        }
        dest.addr = src.addr ^ dest.addr;
        src.addr = src.addr ^ dest.addr;
        return;
    }
}