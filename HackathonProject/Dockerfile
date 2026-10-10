FROM gcc:14
WORKDIR /app
COPY . .
RUN g++ -std=c++20 -O2 *.cpp -o graph
ENTRYPOINT ["./graph"]
