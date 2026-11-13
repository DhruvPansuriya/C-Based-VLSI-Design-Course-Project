; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_2 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x489108 (bvmul arg0_2 arg2_0)))
(let ((?x503485 (bvmul (_ bv4294967295 32) ?x489108)))
(let ((?x327441 (bvmul arg0_2 arg2_1)))
(let ((?x515602 (bvadd ?x327441 ?x503485)))
(and (distinct ?x515602 (_ bv0 32)) true))))))
(check-sat)
