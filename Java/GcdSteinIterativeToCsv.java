// GcdSteinIterativeToCsv.java
import java.io.FileWriter;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;

public class GcdSteinIterativeToCsv {

    static class TestInput {
        String label;
        BigInteger a, b;

        TestInput(String label, BigInteger a, BigInteger b) {
            this.label = label;
            this.a = a;
            this.b = b;
        }
    }

    static class ResultRow {
        BigInteger a, b, gcd;
        double timeSeconds;
        long timeNano;
        double memoryKB;
        String timestamp;

        ResultRow(BigInteger a, BigInteger b, BigInteger gcd, double timeSeconds, long timeNano, double memoryKB, String timestamp) {
            this.a = a;
            this.b = b;
            this.gcd = gcd;
            this.timeSeconds = timeSeconds;
            this.timeNano = timeNano;
            this.memoryKB = memoryKB;
            this.timestamp = timestamp;
        }
    }

    public static BigInteger gcd(BigInteger a, BigInteger b) {
        if (a.equals(BigInteger.ZERO)) return b;
        if (b.equals(BigInteger.ZERO)) return a;

        int commonFactorsOf2 = 0;
        while (a.and(BigInteger.ONE).equals(BigInteger.ZERO) && b.and(BigInteger.ONE).equals(BigInteger.ZERO)) {
            a = a.shiftRight(1);
            b = b.shiftRight(1);
            commonFactorsOf2++;
        }

        while (a.and(BigInteger.ONE).equals(BigInteger.ZERO))
            a = a.shiftRight(1);

        while (!b.equals(BigInteger.ZERO)) {
            while (b.and(BigInteger.ONE).equals(BigInteger.ZERO))
                b = b.shiftRight(1);

            if (a.compareTo(b) > 0) {
                BigInteger temp = a;
                a = b;
                b = temp;
            }

            b = b.subtract(a);
        }

        return a.shiftLeft(commonFactorsOf2);
    }

    public static void main(String[] args) throws Exception {
        TestInput[] tests = {
            new TestInput("1-digit", new BigInteger("8"), new BigInteger("3")),
            new TestInput("2-digit", new BigInteger("48"), new BigInteger("18")),
            new TestInput("3-digit", new BigInteger("210"), new BigInteger("45")),
            new TestInput("4-digit", new BigInteger("1234"), new BigInteger("4321")),
            new TestInput("5-digit", new BigInteger("12345"), new BigInteger("54321")),
            new TestInput("6-digit", new BigInteger("123456"), new BigInteger("789012")),
            new TestInput("7-digit", new BigInteger("1000001"), new BigInteger("7000001")),
            new TestInput("8-digit", new BigInteger("12345678"), new BigInteger("87654321")),
            new TestInput("9-digit", new BigInteger("123456789"), new BigInteger("987654321")),
            new TestInput("10-digit", new BigInteger("1234567890"), new BigInteger("9876543210")),
            new TestInput("Both same", new BigInteger("55555"), new BigInteger("55555")),
            new TestInput("One is zero", new BigInteger("0"), new BigInteger("1234567890")),
            new TestInput("Large + small", new BigInteger("1"), new BigInteger("999999937")),
            new TestInput("Power of 2", new BigInteger("1048576"), new BigInteger("32768")),
            new TestInput("Large primes", new BigInteger("982451653"), new BigInteger("57885161")),
            new TestInput("11-digit", new BigInteger("12345678901"), new BigInteger("10987654321")),
            new TestInput("12-digit", new BigInteger("123457000000"), new BigInteger("210988000000")),
            new TestInput("13-digit", new BigInteger("1234570000000"), new BigInteger("3210990000000")),
            new TestInput("14-digit", new BigInteger("12345700000000"), new BigInteger("43211000000000")),
            new TestInput("15-digit", new BigInteger("123457000000000"), new BigInteger("543211000000000")),
        };

        ArrayList<ResultRow> results = new ArrayList<>();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");

        for (TestInput input : tests) {
            LocalDateTime start = LocalDateTime.now();
            long startMem = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            long startNano = System.nanoTime();

            BigInteger result = gcd(input.a, input.b);

            long endNano = System.nanoTime();
            LocalDateTime end = LocalDateTime.now();
            long endMem = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            double memUsedKB = (endMem - startMem) / 1024.0;
            double timeSec = (endNano - startNano) / 1_000_000_000.0;

            String timestamp = start.format(formatter) + " - " + end.format(formatter);

            results.add(new ResultRow(input.a, input.b, result, timeSec, endNano - startNano, memUsedKB, timestamp));
        }

        try (PrintWriter writer = new PrintWriter(new FileWriter("gcd_stein_iterative_results.csv"))) {
            writer.println("Input A,Input B,GCD Result,Time Taken (s),Time Taken (ns),Memory Used (KB),Timestamp");
            for (ResultRow r : results) {
                writer.printf("%s,%s,%s,%.9f,%d,%.2f,\"%s\"%n",
                    r.a.toString(),
                    r.b.toString(), 
                    r.gcd.toString(),
                    r.timeSeconds,
                    r.timeNano,
                    r.memoryKB,
                    r.timestamp
                );
            }
        }

        System.out.println("✅ CSV file 'gcd_stein_iterative_results.csv' generated successfully.");
    }
}