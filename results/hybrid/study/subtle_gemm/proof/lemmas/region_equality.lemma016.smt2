; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_4 () (_ BitVec 32))
(declare-fun arg0_4 () (_ BitVec 32))
(declare-fun arg1_1 () (_ BitVec 32))
(assert
 (let ((?x329396 (bvmul arg0_4 arg1_4)))
(let ((?x347378 (bvmul (_ bv4294967295 32) ?x329396)))
(let ((?x489108 (bvmul arg0_4 arg1_1)))
(let ((?x328142 (bvadd ?x489108 ?x347378)))
(and (distinct ?x328142 (_ bv0 32)) true))))))
(check-sat)
