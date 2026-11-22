# docker/

`Dockerfile` builds a Linux image with the pinned CBMC 6.11.0, ESBMC and Python, for anyone who
does not want to install the tools by hand:

```sh
docker build -f docker/Dockerfile -t vwe .
docker run --rm -it -v "$PWD":/work -w /work vwe make test
```
