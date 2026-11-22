; benchmark generated from python API
(set-info :status unknown)
(declare-fun arg1_40 () (_ BitVec 32))
(declare-fun arg0_16 () (_ BitVec 32))
(declare-fun arg1_5 () (_ BitVec 32))
(assert
 (let ((?x75233 (bvmul arg0_16 arg1_40)))
(let ((?x62870 (bvmul (_ bv4294967295 32) ?x75233)))
(let ((?x63539 (bvmul arg0_16 arg1_5)))
(let ((?x66143 (bvadd ?x63539 ?x62870)))
(and (distinct ?x66143 (_ bv0 32)) true))))))
(check-sat)
