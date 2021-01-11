setwd("/home/alexis/Dev/Barthou/Projet/data")
library(ggplot2)
library("reshape2")
library( dplyr)


data = read.csv("stencil_permutation.csv")

p = ggplot(data, aes(x=size, y=throughput, group=permutation, color=permutation))+
  geom_line(size=1.3) +
  geom_point(size=3) +
  ggtitle("Stencil permutation performances (AMD)") +
  xlab("Size X=Y=Z") + ylab("Throughput (GFlops/s)") +
  theme( legend.position="bottom",
           legend.title = element_blank(),
         legend.background = element_rect(color = "red"),
           legend.box.just="right",
           plot.title = element_text(hjust = 0.5),
           text = element_text(size=15))

ggsave(plot = p, filename = "permutation.png")

new_data = select(data, throughput, permutation)
means <- aggregate(new_data,by=list(new_data$permutation),mean)
means <- means[,1:2]
gg <- melt(means,id="Group.1")

p <- ggplot(gg,aes(x=variable,y=value,fill=factor(Group.1)))+
  geom_bar(stat="identity",position="dodge")+
  xlab("Permutation")+ylab("Throughput (GFlops/s)") +
  ggtitle("Average throughput by permutation\n (AMD CPU)") +
  theme(plot.title = element_text(hjust = 0.5),
        legend.position = "bottom",
        legend.title = element_blank(),
        axis.text.x = element_blank())

ggsave(plot = p, filename = "throughput_by_permutation.png")

speedup = means
speedup$spdup <- means$throughput / means[7,2]
speedup$permutation = means$Group.1
speedup = speedup[,3:4]
gg <- melt(speedup,id="permutation")

p <- ggplot(gg,aes(x=variable,y=value,fill=factor(permutation)))+
  geom_bar(stat="identity",position="dodge")+
  xlab("Permutation")+ylab("Speedup") +
  ggtitle("Speedup by permutation\n (AMD CPU)") +
  theme(plot.title = element_text(hjust = 0.5),
        legend.position = "bottom",
        legend.title = element_blank(),
        axis.text.x = element_blank())

ggsave(plot = p, filename = "speedup_by_permutation.png")
