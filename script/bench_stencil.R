setwd("/home/alexis/Dev/Barthou/Projet/data")
library(ggplot2)
library("reshape2")


data = read.csv("stencil_permutation.csv")

p = ggplot(data, aes(x=size, y=throughput, group=permutation, color=permutation))+
  geom_line(size=1.3) +
  geom_point(size=3) +
  ggtitle("Stencil permutation performances") +
  xlab("Size X=Y=Z") + ylab("Throughput (GFlops/s)") +
  theme( legend.position="bottom",
           legend.title = element_blank(),
         legend.background = element_rect(color = "red"),
           legend.box.just="right",
           plot.title = element_text(hjust = 0.5),
           text = element_text(size=15))

p
ggsave(plot = p, filename = "permutation.png")