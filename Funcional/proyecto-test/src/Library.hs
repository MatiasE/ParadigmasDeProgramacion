module Library where
import PdePreludat

{- 21/11/2024 -}
-- Guia 1: Ejercicios Basicos.

doble :: Number -> Number
doble numero = numero + numero

esMultiploDeTres :: Number -> Bool
esMultiploDeTres numero = numero `mod` 3 == 0

esMultiploDe :: Number -> Number -> Bool
esMultiploDe numero divisor = numero `mod` divisor == 0

cubo :: Number -> Number
cubo numero = numero * numero * numero

area :: Number -> Number -> Number
area base altura = base * altura

esBisiesto :: Number -> Bool
esBisiesto anio = esMultiploDe anio 4 && not (esMultiploDe anio 100) || esMultiploDe anio 400

celsiusAFahrenheit :: Number -> Number
celsiusAFahrenheit celsius = celsius * 9 / 5 + 32

fahrenheitACelsius :: Number -> Number
fahrenheitACelsius fahrenheit = (fahrenheit - 32) * 5 / 9

haceFrioF :: Number -> Bool
haceFrioF numero = fahrenheitACelsius numero < 8

mcm :: Number -> Number -> Number
mcm a b = a * b / mcd a b

mcd :: Number -> Number -> Number
mcd a 0 = a
mcd a b = mcd b (a `mod` b)

{-
Dispersión
Trabajamos con tres números que imaginamos como el nivel del río Paraná a la altura de Corrientes 
medido en tres días consecutivos; cada medición es un entero que representa una cantidad de cm. 

P.ej. medí los días 1, 2 y 3, las mediciones son: 322 cm, 283 cm, y 294 cm. 
A partir de estos tres números, podemos obtener algunas conclusiones. 

Definir estas funciones: 

dispersion, que toma los tres valores y devuelve la diferencia entre el más alto y el más bajo. 
Ayuda: extender max y min a tres argumentos, usando las versiones de dos elementos. De esa forma 
se puede definir dispersión sin escribir ninguna guarda (las guardas están en max y min, que estamos 
usando). 

diasParejos, diasLocos y diasNormales reciben los valores de los tres días. Se dice que son días 
parejos si la dispersión es chica, que son días locos si la dispersión es grande, y que son días 
normales si no son ni parejos ni locos. Una dispersión se considera chica si es de menos de 30 cm, y 
grande si es de más de un metro. 

Nota: Definir diasNormales a partir de las otras dos, no volver a hacer las cuentas. 
-}

dispersion :: Number -> Number -> Number -> Number
dispersion dia1 dia2 dia3 = max dia1 (max dia2 dia3) - min dia1 (min dia2 dia3)

diasParejos :: Number -> Number -> Number -> String
diasParejos dia1 dia2 dia3 = if dispersion dia1 dia2 dia3 < 30 then "Parejo" else "No Parejo"

diasLocos :: Number -> Number -> Number -> String
diasLocos dia1 dia2 dia3 = if dispersion dia1 dia2 dia3 > 100 then "Loco" else "No Loco"

diasNormales :: Number -> Number -> Number -> String
diasNormales dia1 dia2 dia3 = if not (diasParejos dia1 dia2 dia3 == "Parejo") && not (diasLocos dia1 dia2 dia3 == "Loco") then "Normal" else "No Normal"

{-
    En una plantación de pinos, de cada árbol se conoce la altura expresada en cm. El peso de un pino 
se puede calcular a partir de la altura así: 3 kg x cm hasta 3 metros, 2 kg x cm arriba de los 3 
metros. P.ej. 2 metros ⇒  600 kg, 5 metros ⇒  1000 kg. 

    Los pinos se usan para llevarlos a una fábrica de muebles, a la que le sirven árboles de entre 
400 y 1000 kilos, un pino fuera de este rango no le sirve a la fábrica. Para esta situación: 

    Definir la función pesoPino, recibe la altura de un pino y devuelve su peso. 
    Definir la función esPesoUtil, recibe un peso en kg y devuelve True si un pino de ese peso le 
sirve a la fábrica, y False en caso contrario. 
    Definir la función sirvePino, recibe la altura de un pino y devuelve True si un pino de ese peso 
le sirve a la fábrica, y False en caso contrario. Usar composición en la definición. 
-}

pesoPino :: Number -> Number
pesoPino altura
    | altura <= 300 = altura * 3
    | otherwise = altura * 2

esPesoUtil :: Number -> Bool
esPesoUtil peso = peso >= 400 && peso <= 1000

sirvePino :: Number -> Bool
sirvePino altura = esPesoUtil (pesoPino altura)

{-
    Este ejercicio alguna vez se planteó como un Desafío Café con Leche: Implementar la función 
    esCuadradoPerfecto/1, sin hacer operaciones con punto flotante. Ayuda: les va a venir bien una 
    función auxiliar, tal vez de dos parámetros. Pensar que el primer cuadrado perfecto es 0, para 
    llegar al 2do (1) sumo 1, para llegar al 3ro (4) sumo 3, para llegar al siguiente (9) sumo 5, 
    después sumo 7, 9, 11 etc.. También algo de recursividad van a tener que usar. 
-}

esCuadradoPerfecto :: Number -> Bool
esCuadradoPerfecto numero = esCuadradoPerfectoAux numero 0 1

esCuadradoPerfectoAux :: Number -> Number -> Number -> Bool
esCuadradoPerfectoAux numero actual siguiente
    | actual == numero = True
    | actual > numero = False
    | otherwise = esCuadradoPerfectoAux numero (actual + siguiente) (siguiente + 2)

{- 22/11/2024 -}
-- Guia 2: Aplicacion Parcial y composición.

{-
    Definir una función siguiente, que al invocarla con un número cualquiera me devuelve el resultado de sumar a ese número el 1. 
    Main> siguiente 3
    4
-}

siguiente :: Number -> Number
siguiente numero = numero + 1

{-
    Definir la función mitad que al invocarla con un número cualquiera me devuelve la mitad de dicho número, ej: 
    Main> mitad 5
    2.5
-}

mitad :: Number -> Number
mitad numero = numero / 2

{-
    Definir una función inversa, que invocando a la función con un número cualquiera me devuelva su inversa. 
    Main> inversa 4
    0.25
    Main> inversa 0.5
2.0
-}

inversa :: Number -> Number
inversa numero = 1 / numero

{-
    Definir una función triple, que invocando a la función con un número cualquiera me devuelva el 
triple del mismo.
    Main> triple 5 
    15
-}

triple :: Number -> Number
triple numero = numero * 3

{-
    Definir una función esNumeroPositivo, que invocando a la función con un número cualquiera me 
devuelva true si el número es positivo y false en caso contrario. 
    Main> esNumeroPositivo (-5)
    False
    Main> esNumeroPositivo 5
    True
-}

esNumeroPositivo :: Number -> Bool
esNumeroPositivo numero = numero > 0

{- 
    Composición:
    Nota previa:
    Se base en el concepto matemático de composición de funciones. 
    g(f(x)) = (g o f) x 
    La imagen de f(x) tiene que coincidir con el dominio de g(x) 

    Acá la notación es (g . f) x . Veamos un Ejemplo: 
    g n = even n 
    f n = 3 + n 

    Main> (g . f) 4 
    False 
    Main> (g . f) 3
    True
-}

{- 
    Resolver la función del ejercicio 2 de la guía anterior esMultiploDe/2, utilizando aplicación parcial y 
    composición.
-}

esMultiploDe' :: Number -> Number -> Bool
esMultiploDe' numero divisor = ((== 0) . (mod numero)) divisor

{-
    Resolver la función del ejercicio 5 de la guía anterior esBisiesto/1, 
    utilizando aplicación parcial y composición. (Medio Complicado).
-}


{-
    Resolver la función inversaRaizCuadrada/1, que da un número n devolver la inversa su raíz cuadrada. 
    Main> inversaRaizCuadrada 4 
    0.5 
    Nota: Resolverlo utilizando la función inversa Ej. 2.3, sqrt y composición.
-}

inversaRaizCuadrada :: Number -> Number
inversaRaizCuadrada numero = (sqrt.inversa) numero

{-
    Definir una función incrementMCuadradoN, que invocándola con 2 números m y n, incrementa un valor m 
    al cuadrado de n por Ej: 
    Main> incrementMCuadradoN 3 2 
        11 
    Incrementa 2 al cuadrado de 3, da como resultado 11. Nota: Resolverlo utilizando aplicación parcial y 
    composición. 
-}

incrementMCuadradoN :: Number -> Number -> Number
incrementMCuadradoN m n = ((m+).(^2)) n

{-
    Definir una función esResultadoPar/2, que invocándola con número n y otro m, devuelve true si el resultado 
    de elevar n a m es par. 
    Main> esResultadoPar 2 5 
    True
    Main> esResultadoPar 3 2
    False 
    Nota Obvia: Resolverlo utilizando aplicación parcial y composición.
-}

esResultadoPar :: Number -> Number -> Bool
esResultadoPar n m = (even . ((^) n)) m

-- Guia 3: Tuplas.

{-
    Tuplas:
    Una tupla es un tipo de dato compuesto, que contiene una cantidad fija de elementos y se pueden combinar 
    distintos tipos de elementos, cada elemento está en una posición fija de la estructura. 
    
    Ej: Un alumno viene dado por una tupla de 2 elementos, que está formada por el (legajo, promedio). 

    alumno = (“1104433-8”, 9). 

    Existen algunas funciones predefinidas para obtener cada uno de los elementos de la tupla. Por Ej. si 
    quiero obtener el legajo del alumno puedo hacer lo siguiente: 
    
    Main> fst alumno 
    "1104433-8" 

    Y si quiero obtener el promedio: 
    Main> snd alumno 
    9 

    Otros Ejemplo: 
    fst(4,6) = 4 -- devuelve el primer elemento de la tupla.
    snd(5,7) = 7 -- devuelve el segundo elemento de la tupla.
-}

{- Ejercicios: -}

{-
    Definir las funciones fst3, snd3, trd3, que dada una tupla de 3 elementos devuelva el elemento 
correspondiente, p.ej. 

    Main> snd3 (4,5,6) 
    5
    Main> trd3(4,5,6)
    6
-}

fst3 :: (Number, Number, Number) -> Number
fst3 (a, _, _) = a

snd3 :: (Number, Number, Number) -> Number
snd3 (_, b, _) = b

trd3 :: (Number, Number, Number) -> Number
trd3 (_, _, c) = c

{-
    Definir la función aplicar, que recibe como argumento una tupla de 2 elementos con funciones y un entero, 
    me devuelve como resultado una tupla con el resultado de aplicar el elemento a cada una de la funciones, 
    ej: 

    Main> aplicar (doble,triple) 8 
    (16,24) 
    Main> aplicar ((3+),(2*)) 8 
    (11,16)
-}

aplicar :: ((Number -> a), (Number -> b)) -> Number -> (a, b)
aplicar (f, g) x = (f x, g x)

aplicar' :: ((Number -> Number), (Number -> Number)) -> Number -> (Number, Number)
aplicar' (f, g) x = (f x, g x)

{-
    Definir la función cuentaBizarra, que recibe un par y: si el primer elemento es mayor al segundo devuelve 
    la suma, si el segundo le lleva más de 10 al primero devuelve la resta 2do – 1ro, y si el segundo es más 
    grande que el 1ro pero no llega a llevarle 10, devuelve el producto. Ej: 
    
    Main> cuentaBizarra (5,8)
    40
    Main> cuentaBizarra (8,5)
    13
    Main> cuentaBizarra (5,29)
    24
-}

cuentaBizarra :: (Number, Number) -> Number
cuentaBizarra (numero1, numero2)
    | numero1 > numero2 = numero1 + numero2
    | numero2 - numero1 > 10 = numero2 - numero1
    | otherwise = numero1 * numero2

{-
    Representamos las notas que se sacó un alumno en dos parciales mediante un par (nota1,nota2), p.ej. 
    un patito en el 1ro y un 7 en el 2do se representan mediante el par (2,7). 

    A partir de esto: 
    a. Definir la función esNotaBochazo, recibe un número y devuelve True si no llega a 6, False en caso contrario. 
    No vale usar guardas. 
    b. Definir la función aprobo, recibe un par e indica si una persona que se sacó esas notas aprueba. 
    Usar esNotaBochazo. 
    c. Definir la función promociono, que indica si promocionó, para eso tiene las dos notas tienen que sumar 
    al menos 15 y además haberse sacado al menos 7 en cada parcial. 
    d. Escribir una consulta que dado un par indica si aprobó el primer parcial, usando esNotaBochazo y 
    composición. La consulta tiene que tener esta forma (p.ej. para el par de notas (5,8)).

    Main> (... algo ...) (5,8) 
-}

esNotaBochazo :: Number -> Bool
esNotaBochazo numero = numero < 6

aprobo :: (Number, Number) -> Bool
aprobo (nota1, nota2) = not (esNotaBochazo nota1) && not (esNotaBochazo nota2)

promociono :: (Number, Number) -> Bool
promociono (nota1, nota2) = (nota1 + nota2 >= 15) && (nota1 >= 7) && (nota2 >= 7)

aproboPrimerParcial :: (Number, Number) -> Bool
aproboPrimerParcial = (not . esNotaBochazo) . fst

{-
    Siguiendo con el dominio del ejercicio anterior, tenemos ahora dos parciales con dos recuperatorios, 
    lo representamos mediante un par de pares ((parc1,parc2),(recup1,recup2)). 

    Si una persona no rindió un recuperatorio, entonces ponemos un "-1" en el lugar correspondiente. 

    Observamos que con la codificación elegida, siempre la mejor nota es el máximo entre nota del parcial y 
    nota del recuperatorio. 

    Considerar que vale recuperar para promocionar. En este ejercicio vale usar las funciones que se definieron 
    para el anterior. 

    a. Definir la función notasFinales que recibe un par de pares y devuelve el par que corresponde a las notas 
    finales del alumno para el 1er y el 2do parcial. P.ej. 
    
    Main> notasFinales ((2,7),(6,-1)) 
    (6,7) 
    Main> notasFinales ((2,2),(6,2)) 
    (6,2) 
    Main> notasFinales ((8,7),(-1,-1)) 
    (8,7) 

    b. Escribir la consulta que indica si un alumno cuyas notas son ((2,7),(6,-1)) recursa o no. O sea, la respuesta 
    debe ser True si recursa, y False si no recursa. Usar las funciones definidas en este punto y el anterior, y 
    composición. La consulta debe tener esta forma:
    Main> (... algo ...) ((2,7),(6,-1)) 

    c. Escribir la consulta que indica si un alumno cuyas notas son ((2,7),(6,-1)) recuperó el primer parcial. Usar 
    composición. La consulta debe tener esta forma:
    Main> (... algo ...) ((2,7),(6,-1)) 

    d. Definir la función recuperoDeGusto que dado el par de pares que representa a un alumno, devuelve True si el 
    alumno, pudiendo promocionar con los parciales (o sea sin recup.), igual rindió al menos un recup. Vale 
    definir funciones auxiliares. Hacer una definición que no use pattern matching, en las eventuales funciones 
    auxiliares tampoco; o sea, manejarse siempre con fst y snd.
-}

notas = ((2,7),(6,-1))

notasFinales :: ((Number, Number), (Number, Number)) -> (Number, Number)
notasFinales ((parc1, parc2), (recup1, recup2)) = (max parc1 recup1, max parc2 recup2)

recursante :: ((Number, Number), (Number, Number)) -> Bool
recursante ((parc1, parc2), (recup1, recup2)) = not (aprobo ((max parc1 recup1), (max parc2 recup2)))

recuperoPrimerParcial :: ((Number, Number), (Number, Number)) -> Bool
recuperoPrimerParcial ((parc1, parc2), (recup1, recup2)) = recup1 /= -1

recuperoSegundoParcial :: ((Number, Number), (Number, Number)) -> Bool
recuperoSegundoParcial ((parc1, parc2), (recup1, recup2)) = recup2 /= -1

recuperoDeGusto :: ((Number, Number), (Number, Number)) -> Bool
recuperoDeGusto ((parc1, parc2), (recup1, recup2)) = promociono (parc1, parc2) && (recuperoPrimerParcial ((parc1, parc2), (recup1, recup2)) || recuperoSegundoParcial ((parc1, parc2), (recup1, recup2)))

{-
    Definir la función esMayorDeEdad, que dada una tupla de 2 elementos (persona, edad) me devuelva True si es 
    mayor de 21 años y False en caso contrario. Por Ej:.

    Main> esMayorDeEdad (juan,18) 
    False 
    Nota: Definir la función utilizando aplicación parcial y composición.
-}

esMayorDeEdad :: (String, Number) -> Bool
esMayorDeEdad (_, edad) = edad > 21

{-
    Definir la función calcular, que recibe una tupla de 2 elementos, si el primer elemento es par lo duplica, 
    sino lo deja como está y con el segundo elemento en caso de ser impar le suma 1 y si no deja esté último como
    esta. 

    Main> calcular (4,5)
    (8,6) 
    Main> calcular (3,7)
    (3,8) 
    
    Nota: Resolverlo utilizando aplicación parcial y composición.
-}

calcular :: (Number, Number) -> (Number, Number)
calcular (numero1, numero2) 
    | (even numero1 && odd numero2) = (numero1 * 2, numero2+1)
    | (even numero1 && not (odd numero2)) = (numero1 * 2, numero2)
    | (not (even numero1) && odd numero2) = (numero1, numero2 + 1)
    | (not (even numero1) && not (odd numero2)) = (numero1, numero2)

-- Guia 4: Orden Superior y Listas.
{-
    Funcional 4: Listas + Orden Superior
    Listas
    Existen funciones predefinidas en el Prelude que nos permiten manejar listas por ej: 
    
    head / tail / !! (infija, devuelve el elemento en la posición i, base 0). 
    
    Ejemplos 
    head [2,4,6,8] = 2 
    tail [2,4,6,8] = [4,6,8] 
    [2,4,6,8] !! 1 = 4 	-- base 0!! 
    null [] = True 	--Indica si una lista está vacía. 
    null [2,4,5] = False 
    concat [[1..4],[11..13],[21,34]] = [1,2,3,4,11,12,13,21,34] -- ”aplana” una lista de listas. 

    Si se quiere calcular el promedio, dada una lista números y se está usando prelude puro, se puede 
    hacer algo así: 
    sum [3,5,6] / fromInteger(toInteger(length[3,5,6])) 
    4.66666666666667 
    Tener en cuenta que en la notación [a..b] ni a ni b tienen por qué ser constantes, pueden ser 
    cualquier expresión, p.ej 
    [1..head [6,3,8]] 		[min (3+4) (3*4)..max (3+4) (3*4)] 

    Ejercicio Extra
    Para cada función que definan, obtengan su tipo y después verifiquen con lo que les dice el :t. 
    ¡Pero háganlo primero a mano! si no, no practican. Hacer lo mismo con las funciones head, tail 
    y !!. Para preguntar por el tipo de una función infija, la ponen entre paréntesis, p.ej. :t (!!) 
-}

{-
    Ejercicios
    Definir una función que sume una lista de números. 
    Nota: Investigar sum 
-}

sumarLista :: [Number] -> Number
sumarLista lista = sum lista

{-
    Durante un entrenamiento físico de una hora, cada 10 minutos de entrenamiento se tomóo la frecuencia cardíaca 
    de uno de los participantes obteniéndose un total de 7 muestras que son las siguientes:
frecuenciaCardiaca = [80, 100, 120, 128, 130, 123, 125] 

    Comienza con un frecuencia de 80 min 0. 
    A los 10 min la frecuencia alcanza los 100 
    A los 20 min la frecuencia es de 120, 
    A los 30 min la frecuencia es de 128
    A los 40 min la frecuencia es de 130, …etc.. 
    A los 60 min la frecuencia es de 125 frecuenciaCardiaca es un función constante. 

    a. Definir la función promedioFrecuenciaCardiaca, que devuelve el promedio de la frecuencia cardíaca. 
    Main> promedioFrecuenciaCardiaca 
    115.285714285714
    
    b. Definir la función frecuenciaCardiacaMinuto/1, que recibe m que es el minuto en el cual quiero conocer la frecuencia cardíaca, m puede ser a los 10, 20, 30 ,40,..hasta 60. 
    Main> frecuenciaCardiacaMomento 30 
    128 

    Ayuda: Vale definir una función auxiliar para conocer el número de muestra. 
    
    c- Definir la función frecuenciasHastaMomento/1, devuelve el total de frecuencias que se obtuvieron hasta el minuto m. 
    Main> frecuenciasHastaMomento 30 
    [80, 100, 120, 128] 
    Ayuda: Utilizar la función take y la función auxiliar definida en el punto anterior. 
-}

frecuenciaCardiaca = [80, 100, 120, 128, 130, 123, 125] 

promedioFrecuenciaCardiaca :: [Number] -> Number
promedioFrecuenciaCardiaca lista = (sumarLista lista) / (longitud lista)

longitud :: [Number] -> Number
longitud lista = length lista

frecuenciaCardiacaMomento :: Number -> Number
frecuenciaCardiacaMomento minuto = frecuenciaCardiaca !! (minuto `div` 10)

frecuenciasHastaMomento :: Number -> [Number]
frecuenciasHastaMomento minuto = take (minuto `div` 10) frecuenciaCardiaca

{-
    Definir la función esCapicua/1, si data una lista de listas, me devuelve si la concatenación de las 
    sublistas es una lista capicua..Ej: 

    Main> esCapicua ["ne", "uqu", "en"] 
    True 
    Porque “neuquen” es capicua.
    Ayuda: Utilizar concat/1, reverse/1. 
-}

esCapicua :: [[String]] -> Bool
esCapicua lista = concat lista == reverse (concat lista)

{-
    Se tiene información detallada de la duración en minutos de las llamadas que se llevaron a cabo en un período 
    determinado, discriminadas en horario normal y horario reducido. 

    duracionLlamadas = (("horarioReducido",[20,10,25,15]),(“horarioNormal”,[10,5,8,2,9,10])). 

    a. Definir la función cuandoHabloMasMinutos, devuelve en que horario se habló más cantidad de minutos, en el de 
    tarifa normal o en el reducido. 

    Main> cuandoHabloMasMinutos 
    “horarioReducido” 

    b.Definir la función cuandoHizoMasLlamadas, devuelve en que franja horaria realizó más cantidad de llamadas, 
    en el de tarifa normal o en el reducido. 

    Main> cuandoHizoMasLlamadas 
    “horarioNormal” 

    Nota: Utilizar composición en ambos casos 
-}

duracionLlamadas = (("horarioReducido",[20,10,25,15]),("horarioNormal",[10,5,8,2,9,10]))

cuandoHabloMasMinutos :: ((String, [Number]), (String, [Number])) -> String
cuandoHabloMasMinutos (horarioReducido, horarioNormal)
    | (sum.snd) horarioReducido > (sum.snd) horarioNormal = "horarioReducido"
    | otherwise = "horarioNormal"

cuandoHizoMasLlamadas :: ((String, [Number]), (String, [Number])) -> String
cuandoHizoMasLlamadas (horarioReducido, horarioNormal)
    | (length.snd) horarioReducido > (length.snd) horarioNormal = "horarioReducido"
    | otherwise = "horarioNormal"

{-
    Orden Superior:
        Nota:
            Si una función f recibe en algunos de sus argumentos una función entonces f es una función de orden 
            superior. 
        
        Veamos un ejemplo. 
        Si quiero aplicar a un número n una función determinada podría hacer.. 
        aplicar f n = f n 
        Por ejemplo, le paso como argumento una función aplicada parcialmente: (+3), (4*). 
        Main> aplicar (+ 3) 2 
        5 
        Main> aplicar (4 *) 3 
        12 
-}

{-
    Ejercicios:
-}

{-
    Definir la función existsAny/2, que dadas una función booleana y una tupla de tres elementos devuelve True 
    si existe algún elemento de la tupla que haga verdadera la función. 

    Main> existsAny even (1,3,5) 
    False 

    Main> existsAny even (1,4,7) 
    True 
    porque even 4 da True 

    Main> existsAny (0>) (1,-3,7) 
    True 
    porque even -3 es negativo
-}

existsAny :: (Number -> Bool) -> (Number, Number, Number) -> Bool
existsAny funcion (numero1, numero2, numero3) = funcion numero1 || funcion numero2 || funcion numero3

existsAny' :: (Number -> Bool) -> [Number] -> Bool
existsAny' funcion lista = any funcion lista

{-
    Definir la función mejor/3, que recibe dos funciones y un número, y devuelve el resultado de la función que 
    dé un valor más alto. P.ej. 
    
    Main> mejor cuadrado triple 1 
    3 
    (pues triple 1 = 3 > 1 = cuadrado 1) 

    Main> mejor cuadrado triple 5 
    25 

    (pues cuadrado 5 = 25 > 15 = triple 5) 
    Nota: No olvidar la función max. 
-}

mejor :: (Number -> Number) -> (Number -> Number) -> Number -> Number
mejor funcion1 funcion2 numero = max (funcion1 numero) (funcion2 numero)

{-
    Definir la función aplicarPar/2, que recibe una función y un par, y devuelve el par que resulta de aplicar 
    la función a los elementos del par. P.ej. 

    Main> aplicarPar doble (3,12) 
    (6,24) 

    Main> aplicarPar even (3,12) 
    (False, True) 

    Main> aplicarPar (even . doble) (3,12) 
    (True, True) 

-}

aplicarPar :: (a -> b) -> (a, a) -> (b, b)
aplicarPar funcion (primerElemento, segundoElemento) = (funcion primerElemento, funcion segundoElemento)

{-
    Definir la función parDeFns/3, que recibe dos funciones y un valor, y devuelve un par ordenado que es el 
    resultado de aplicar las dos funciones al valor. P.ej. 
Main> parDeFns even doble 12 
(True, 24)
-}

parDeFns :: (a -> b) -> (a -> c) -> a -> (b, c)
parDeFns funcion1 funcion2 valor = (funcion1 valor, funcion2 valor)

{-
    Orden Superior + Listas
    Además existen funciones de orden superior predefinidas que nos permiten trabajar con listas. Por ej: 
    Si quiero filtrar todos los elementos de una lista determinada que cumplen una determinada condición 
    puedo utilizar filter. 

    paresEntre n1 n2 = filter even [n1..n2] 

    Otro Ejemplo de funciones de orden superior predefinidas que se utiliza mucho es el map 
    Si quiero transformar una lista de elementos, puedo hacer: 
    sumarN n lista = map (+n) lista 
    Suma n a cada elemento de la lista. 
    sumarElDobleDeN n lista = map (+ (doble n)) lista 
    
    Aplica el doble a cada elemento de la lista. 

    Otras funciones de orden superior: 

    all even [2,48,14] = True -- Indica si todos los elementos de una lista cumplen una condición. 
    all even [2,49,14] = False 
    any even [2,48,14] = True -- Indica si algunos de los elementos de una lista cumplen una condición
-}

{-
    Ejercicio Extra
    Obtener :t el tipo de las funciones (4+) y (+4). Fíjense que en la segunda dice algo de "flip", los 
    curiosos pueden investigar un poco más qué es eso.
-}

{-
    Definir la función esMultiploDeAlguno/2, que recibe un número y una lista y devuelve True si el número 
    es múltiplo de alguno de los números de la lista. P.ej. 

    Main> esMultiploDeAlguno 15 [2,3,4] 
    True, 
    porque 15 es múltiplo de 3 

    Main> esMultiploDeAlguno 34 [3,4,5] 
    False 
    
    porque 34 no es múltiplo de ninguno de los 3 
    Nota: Utilizar la función any/2. 
-}

esMultiploDeAlguno :: Number -> [Number] -> Bool
esMultiploDeAlguno numero lista = any (\x -> numero `mod` x == 0) lista

esMultiploDeAlguno' :: Number -> [Number] -> Bool
esMultiploDeAlguno' numero lista = any ((== 0).(`mod` numero)) lista

esMultiploDeTodos :: Number -> [Number] -> Bool
esMultiploDeTodos numero lista = all (\x -> numero `mod` x == 0) lista

esMultiploDeTodos' :: Number -> [Number] -> Bool
esMultiploDeTodos' numero lista = all ((==0).(`mod` numero)) lista

{-
    Armar una función promedios/1, que dada una lista de listas me devuelve la lista de los promedios 
    de cada lista-elemento. P.ej. 

    Main> promedios [[8,6],[7,9,4],[6,2,4],[9,6]] 
    [7,6.67,4,7.5] 

    Nota: Implementar una solución utilizando map/2. 
-}

promedios :: [[Number]] -> [Number]
promedios lista = map promedio lista

promedio :: [Number] -> Number
promedio lista = (sum lista) / (longitud lista)

{-
    Armar una función promediosSinAplazos que dada una lista de listas me devuelve la lista de los 
    promedios de cada lista-elemento, excluyendo los que sean menores a 4 que no se cuentan. P.ej. 

    Main> promediosSinAplazos [[8,6],[6,2,6]] 
    [7,6] 
    
    Nota: Implementar una solución utilizando map/2. 
-}

promediosSinAplazos :: [[Number]] -> [Number]
promediosSinAplazos lista = filter (>4) (map promedio lista)

{--}

mejoresNotas :: [[Number]] -> [Number]
mejoresNotas lista = map maximo lista

maximo :: [Number] -> Number
maximo lista = maximum lista

aproboLista :: [Number] -> Bool
aproboLista lista = all (>=6) lista

aproboLista' :: [Number] -> Bool
aproboLista' lista = minimum lista >= 6

aproboLista'' :: [Number] -> Bool
aproboLista'' lista = all (>=6) lista

mejoresNotas' :: [[Number]] -> [Number]
mejoresNotas' lista = map maximo lista

aprobaronTodos :: [[Number]] -> [[Number]]
aprobaronTodos lista = filter aproboLista lista

divisores :: Number -> [Number]
divisores numero = filter (\x -> numero `mod` x == 0) [1..numero]

divisores' :: Number -> [Number]
divisores' numero = filter ((==0).(numero `mod`)) [1..numero]