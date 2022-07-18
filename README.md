[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-dark-v6.png#gh-dark-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/fdiniello/Signaloid-Demo-Bernoulli#gh-dark-mode-only)
[<img src="https://assets.signaloid.io/add-to-signaloid-cloud-logo-light-v6.png#gh-light-mode-only" alt="[Add to signaloid.io]" height="30">](https://signaloid.io/repositories?connect=https://github.com/fdiniello/Signaloid-Demo-Bernoulli#gh-light-mode-only)

# Signaloid Challenge: Bernoulli equation

Here is the challenge:

Two-week challenge (due Friday 11th September 2023)

The Bernoulli equation can be used to create a simple model of lift generation of an airfoil as a function of the airfoil’s geometry, the pressure, density, and velocity of fluid around the airfoil, and other parameters such as elevation.

Create a simple model, as a C program running on the Signaloid Cloud Developer Platform, for the lift generation of an airfoil based on the Bernoulli equation or based on some other reasonable model and assumptions of your choosing. You may choose, for example, to include wind speed as calculated by a Pitot tube, which will then introduce the Pitot tube’s parameters into the model. You might also choose to include parameters such as ambient temperature, humidity, or elevation, to determine the values of other model parameters such as densities.

Given the model you created, determine reasonable measurement uncertainties for each of the parameters. It is OK to use uniform distributions if you only know a tolerance, or you could use non-uniform empirical distributions if you can find such relevant information online.

Implement your model as a C program and test it using the Signaloid Cloud Developer Platform. You can use the functionality of the platform to inject distributions for those model parameters which are uncertain. Identify any assumptions the model or its implementation on the Signaloid C0 processor must make in order to provide correct results. Document the example by providing clearly-documented source code as well as a well-written but brief README.md and place it in a public GitHub repository. You can find some examples [0] of documented repositories that you can easily run on the Signaloid Cloud Developer Platform at Signaloid’s GitHub page.

You can use one of our existing example repositories [1] as a template and follow the directions in that repository’s README.md to run it on the Signaloid Cloud Developer Platform. You can also find additional documentation online [2]. We will not provide any additional help or feedback in the process, although, like any other user of the platform, you can send mail to developer-support@signaloid.com if you have questions about problems with the platform. We will not answer any questions specific to the challenge.


[0] [https://github.com/signaloid/Signaloid-Demo-Metall...](https://github.com/signaloid/Signaloid-Demo-Metallurgy-BrownHamModel)

[1] [https://github.com/signaloid/Signaloid-Demo-Genera...](https://github.com/signaloid/Signaloid-Demo-General-C/generate)

[2] [https://docs.signaloid.io](https://docs.signaloid.io)
