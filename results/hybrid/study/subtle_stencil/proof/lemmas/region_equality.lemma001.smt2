; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg2_0 () (_ BitVec 32))
(declare-fun arg0_1 () (_ BitVec 32))
(declare-fun arg2_1 () (_ BitVec 32))
(assert
 (let ((?x524057 (bvmul arg0_1 arg2_0)))
(let ((?x349593 (bvmul (_ bv4294967295 32) ?x524057)))
(let ((?x347018 (bvmul arg0_1 arg2_1)))
(let ((?x349501 (bvadd ?x347018 ?x349593)))
(and (distinct ?x349501 (_ bv0 32)) true))))))
(check-sat)
