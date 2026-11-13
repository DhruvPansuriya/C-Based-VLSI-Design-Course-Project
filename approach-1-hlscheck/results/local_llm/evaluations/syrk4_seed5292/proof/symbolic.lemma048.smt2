; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg0_7 () (_ BitVec 32))
(declare-fun arg0_13 () (_ BitVec 32))
(assert
 (let ((?x778 (bvmul arg0_13 arg0_7)))
(let ((?x6255 (bvmul (_ bv4294967295 32) ?x778)))
(let ((?x1105 (bvmul arg0_13 arg0_13)))
(let ((?x30369 (bvadd ?x1105 ?x6255)))
(and (distinct ?x30369 (_ bv0 32)) true))))))
(check-sat)
